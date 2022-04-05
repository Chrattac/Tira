#include "airport.h"



// Class Runway Methods:
//--------------------------------------------

Runway::Runway(){
   purpose = any;
   queue_limit = 0;
   num_land_requests = num_takeoff_requests = 0;
   num_landings = num_takeoffs = 0;
   num_land_refused = num_takeoff_refused = 0;
   num_land_accepted = num_takeoff_accepted = 0;
   land_wait = takeoff_wait = idle_time = 0;
}

Runway::Runway(int limit, Runway_purpose runway_purpose) :
queue_limit(limit), purpose(runway_purpose)
/*
Post:  The Runway data members are initialized to record no
       prior Runway use and to record the limit on queue sizes.
*/

{

   num_land_requests = num_takeoff_requests = 0;
   num_landings = num_takeoffs = 0;
   num_land_refused = num_takeoff_refused = 0;
   num_land_accepted = num_takeoff_accepted = 0;
   land_wait = takeoff_wait = idle_time = 0;

}

Error_code Runway::can_land(const Plane &current)
/*
Post:  If possible, the Plane current is added to the
       landing Queue; otherwise, an Error_code of overflow is
       returned. The Runway statistics are updated.
Uses:  Queue.
*/

{
   Error_code result;
   if (landing.size() < queue_limit){
      result = landing.append(current);
   }
   else
      result = fail;
   num_land_requests++;

   if (result != success)
      num_land_refused++;
   else
      num_land_accepted++;

   return result;
}

Error_code Runway::can_depart(const Plane &current)
/*
Post:  If possible, the Plane current is added to the
       takeoff Queue; otherwise, an Error_code of overflow is
       returned. The Runway statistics are updated.
Uses:  class Queue.
*/

{
   Error_code result;
   if (takeoff.size() < queue_limit){
      result = takeoff.append(current);
   }
   else
      result = fail;

   num_takeoff_requests++;
   
   if (result != success)
      num_takeoff_refused++;
   else
      num_takeoff_accepted++;

   return result;
}

Runway_activity Runway::activity(int time, Plane &moving)
/*
Post:  If the landing Queue has entries, its front
       Plane is copied to the parameter moving
       and a result  land is returned. Otherwise,
       if the takeoff Queue has entries, its front
       Plane is copied to the parameter moving
       and a result  takeoff is returned. Otherwise,
       idle is returned. Runway statistics are updated.
Uses:  class Queue.
*/

{
   Runway_activity in_progress;

   if (in_use) in_progress = busy;
   else if ( !landing.empty() && !( takeoff.empty() && takeoff_priority ) ) {
      landing.retrieve(moving);
      land_wait += time - moving.started();
      num_landings++;
      in_progress = land;
      landing.serve();
      in_use = true;
   }

   else if ( !takeoff.empty() && !( landing.empty() && landing_priority ) ) {
      takeoff.retrieve(moving);
      takeoff_wait += time - moving.started();
      num_takeoffs++;
      in_progress = take_off;
      takeoff.serve();
      in_use = true;
   }

   else {
      in_progress = idle;
      
      if(idle_check_time != time){
         idle_time++;
         idle_check_time=time;
      }
   }
   return in_progress;
}



int Runway::get_landings_requests() const { return num_land_requests; }
int Runway::get_landings() const { return num_landings; }
int Runway::get_landing_accepted() const { return num_land_accepted; }
int Runway::get_landings_refused() const { return num_land_refused; }
int Runway::get_land_wait() const { return land_wait; }

int Runway::get_takeoffs_requests() const { return num_takeoff_requests; }
int Runway::get_takeoffs() const { return num_takeoffs; }
int Runway::get_takeoffs_accepted() const { return num_takeoff_accepted; }
int Runway::get_takeoffs_refused() const { return num_takeoff_refused; }
int Runway::get_takeoff_wait() const { return takeoff_wait; }

int Runway::get_idle_time() const { return idle_time; }

bool Runway::get_landing_full() const { return landing.full(); }
bool Runway::get_landing_empty() const { return landing.empty(); }
int Runway::get_landing_size() const { return landing.size(); }

bool Runway::get_takeoff_full() const { return takeoff.full(); }
bool Runway::get_takeoff_empty() const { return takeoff.empty(); }
int Runway::get_takeoff_size() const { return takeoff.size(); }

bool Runway::get_landing_priority() const{ return landing_priority;}
bool Runway::get_takeoff_priority() const{ return takeoff_priority;}

void Runway::set_landing_priority(bool priority){ landing_priority = priority; }
void Runway::set_takeoff_priority(bool priority){ takeoff_priority = priority; }

bool Runway::queues_empty() const {return ( takeoff.empty()+landing.empty() ); }

Error_code Runway::add_landing(const Plane &current) { return landing.append(current); }
Error_code Runway::add_takeoff(const Plane &current) { return takeoff.append(current); }

Error_code Runway::remove_landing(Plane &current) { return landing.retrieve_and_serve(current); }
Error_code Runway::remove_takeoff(Plane &current) { return takeoff.retrieve_and_serve(current); }

void Runway::reset_usage() { in_use = false; }
bool Runway::get_usage() const { return in_use; }

Runway_purpose Runway::get_purpose() const { return purpose; }
