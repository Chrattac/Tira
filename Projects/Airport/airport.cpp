#include "airport.h"

Airport::Airport(int limit, uint8_t runway_count) : Runway()
{   // Constructor asking for purpose of runaways
    queue_limit = limit;

    char choice = ' ';
    //Initialize each runway separately
    for(uint8_t i = 0; i<runway_count; i++){
        if(choice != 'b'){
        input: 
        std::cout << "\nGive the purpose for runaway# " << i+1 << ":\n"
            << "[a] for arrivals, [x] for strict arrivals,\n"
            << "[d] for departures, [z] for strict departures,\n"
            << "[b] to set rest of the runways as both: ";

            choice = get_command();

        }
        
        switch(choice){
            case 'a':
                runways.push_back(new Runway(queue_limit, arrivals));
                break;
            case 'd':
                runways.push_back(new Runway(queue_limit, departures));
                break;
            case 'x':
                runways.push_back(new Runway(queue_limit, arrivals_strict));
                break;
            case 'z':
                runways.push_back(new Runway(queue_limit, departures_strict));
                break;
            case 'b':
                runways.push_back(new Runway(queue_limit));
                break;
            default:
                std::cout << "something went wrong!\n";
                goto input; //goto for simple retry.
        }
    }
    std::cin.clear();
    std::cin.ignore(100, '\n');
    
    bool cntn;
    
    do{
        std::cout << "Do you want to set priority for \n"
            << "[L]andings, [T]akeoffs, [N]o? ";
        std::cin >> choice;
        choice = tolower(choice);

        if( choice == 'n' || choice == 'l' || choice == 't' ) cntn = true;
        else {

            cntn = false;
            std::cout << "invalid choice!\n";
        
        }
    
    }while(!cntn);

    if(choice != 'n'){
        if(choice == 'l') {
            set_landing_priority( true );
            for( Runway *r : runways ) r->set_landing_priority( true );
        }
        if(choice == 't') {
            set_takeoff_priority( true );
            for( Runway *r : runways ) r->set_takeoff_priority( true );
        }
    }

}

Airport::~Airport(){
    for(int i = 0; i<runways.size(); i++) delete runways[i];
    runways.clear();
}   

Error_code Airport::can_land(const Plane &current)
/*
Post:  If possible, the Plane current is added to the
       landing Queue; otherwise, an Error_code of overflow is
       returned. The Runway statistics are updated.
Uses:  Queue.
*/

{
    
    Error_code result;

    for( Runway *r : runways ){
        if( r->get_purpose() == arrivals || r->get_purpose() == arrivals_strict || r->get_purpose() == any ){
            result = r->can_land(current);

            if ( result == success ) break;
        }
    }

    //if landing priority is set also check departures, separate loop to avoid
    //arrivals to fill departures in case it comes 1st
    if( get_landing_priority() && result != success){
        for ( Runway *r : runways ){
            if(r->get_purpose() == departures) result = r->can_land(current);
            if ( result == success ) break;
        }
    }

    num_land_requests++;

    if (result != success) num_land_refused++;
    else num_land_accepted++;

    return result;
}

Error_code Airport::can_depart(const Plane &current)
/*
Post:  If possible, the Plane current is added to the
       takeoff Queue; otherwise, an Error_code of overflow is
       returned. The Runway statistics are updated.
Uses:  class Queue.
*/

{
    Error_code result;

    for( Runway *r : runways ){
        if ( r->get_purpose() == departures || r->get_purpose() == departures_strict || r->get_purpose() == any )
            result=r->can_depart(current);

            if ( result == success ) break;
    }
    
    //if takeoff priority is set:
    if( get_takeoff_priority()  && result != success ){
        for ( Runway *r : runways ){
            if(r->get_purpose() == arrivals) result = r->can_depart(current);
            if ( result == success ) break;
        }
    }
    

    num_takeoff_requests++;

    if (result != success) num_takeoff_refused++;
    else num_takeoff_accepted++;

    return result;
}


Error_code Airport::temporary_runway_use(Runway *runway, const bool priorityfull){
    Error_code error = success;

    bool done = false,
    arrivals_flag = false,
    takeoff_flag = false;

    //First check if check already done and then wheter there is anything on queues for other runways
    //Second expression is for priority to check wheter there is priority runway full
    //Since we come here also if there is either priority set even if runway wasn't about to go idle
    if( priorityfull && get_landing_priority() ) arrivals_flag = true;
    else if (priorityfull && get_takeoff_priority() ) takeoff_flag = true;
    else{
        for( Runway *r : runways ){
            if(r != runway){
                if( !arrivals_flag && !r->get_landing_empty() ) 
                    arrivals_flag = true;
                if( !takeoff_flag && !r->get_takeoff_empty() )
                    takeoff_flag = true;
            }
            //No need to check further runways;
            if(arrivals_flag && takeoff_flag) break;
        }
    }

    //If transfer runway's queue is full (ie. flag set due to itself previously), 
    //set flag back to false
    if(runway->get_landing_full()) arrivals_flag = false;
    if(runway->get_takeoff_full()) takeoff_flag = false;

    //If flags have been set, proceed to transfer plane
    if(arrivals_flag || takeoff_flag){
        Plane transfer;
        for ( Runway *r : runways ){
            if(r != runway){
                switch ( runway->get_purpose() ){
                    case arrivals_strict: //only take arrivals
                        if( arrivals_flag ){
                            if(!r->get_landing_empty()){
                                error = r->remove_landing(transfer);
                                if( error == success ) runway->add_landing(transfer);
                                if( error == success ) done = true;
                            }
                        }

                        break;

                    case arrivals:        //prioritize arrivals
                        if( arrivals_flag ){
                            if(!r->get_landing_empty()){
                                error = r->remove_landing(transfer);
                                if( error == success ) runway->add_landing(transfer);
                                if( error == success ) done = true;
                            }
                        }
                        else{
                            if(!r->get_takeoff_empty()){
                                error = r->remove_takeoff(transfer);
                                if( error == success ) runway->add_takeoff(transfer);
                                if( error == success ) done = true;
                            }
                        }

                        break;

                    case departures_strict: //only take takeoffs
                        if( takeoff_flag ){
                            if(!r->get_takeoff_empty()){
                                error = r->remove_landing(transfer);
                                if( error == success ) runway->add_takeoff(transfer);
                                if( error == success ) done = true;
                            }
                        }

                        break;

                    case departures:        //prioritize takeoffs
                        if( takeoff_flag ){
                            if(!r->get_takeoff_empty()){
                                error = r->remove_takeoff(transfer);
                                if( error == success ) runway->add_takeoff(transfer);
                                if( error == success ) done = true;
                            }
                        }
                        else{
                            if(!r->get_landing_empty()){
                                error = r->remove_landing(transfer);
                                if( error == success ) runway->add_landing(transfer);
                                if( error == success ) done = true;
                            }
                        }

                        break;

                    case any:               //prioritize arrivals, same as "arrivals"
                        if( arrivals_flag ){
                            if(!r->get_landing_empty()){
                                error = r->remove_landing(transfer);
                                if( error == success ) runway->add_landing(transfer);
                                if( error == success ) done = true;
                            }
                        }
                        else{
                            if(!r->get_takeoff_empty()){
                                error = r->remove_takeoff(transfer);
                                if( error == success ) runway->add_takeoff(transfer);
                                if( error == success ) done = true;
                            }
                        }

                        break;
                }
            }

            if(done) break;             // break as soon as plane received

        }

    }

    return error;
}

void Airport::reset_runways(){
    for(Runway *r : runways) r->reset_usage();
}


void Airport::activity(int time, Plane &moving, bool& landing, bool& takeoff, bool& bool_idle)
{
    landing = false;
    takeoff = false;
    bool_idle = false;
    
    bool priority_full = false;

        if(get_landing_priority())
            for( Runway *r : runways ) if( r->get_landing_full() ) {
                priority_full = true;
                break;
            }

        if(get_takeoff_priority())
            for( Runway *r : runways ) if( r->get_takeoff_full() ) {
                 priority_full = true;
                 break;
            }

    for(Runway *r : runways){
        if(r->queues_empty() || priority_full) 
            temporary_runway_use(r, priority_full);

        switch(r->activity(time, moving)){
            case land:
                landing = true;
                break;
            case take_off:
                takeoff = true;
                break;
            case idle:
                bool_idle = true;
                break;
            case busy:
                break;

        // break from the for loop as soon as the plane is handled to avoid multiplication
        if( landing || takeoff || bool_idle ) break;
        }
    }
}

void Airport::shut_down(int time)
/*
Post: Runway usage statistics are summarized and printed.
*/

{
    for(Runway *r : runways){
        num_landings +=r->get_landings();
        num_takeoffs +=r->get_takeoffs();
        landings_size += r->get_landing_size();
        take_off_size += r->get_takeoff_size();
        land_wait += r->get_land_wait();
        takeoff_wait += r->get_takeoff_wait();
        idle_time += r->get_idle_time();
    }

    std::cout << "Simulation has concluded after " << time << " time units." << std::endl
        << "Total number of planes processed "
        << (num_land_requests + num_takeoff_requests) << std::endl
        << "Total number of planes asking to land "
        << num_land_requests << std::endl
        << "Total number of planes asking to take off "
        << num_takeoff_requests << std::endl
        << "Total number of planes accepted for landing "
        << num_land_accepted << std::endl
        << "Total number of planes accepted for takeoff "
        << num_takeoff_accepted << std::endl
        << "Total number of planes refused for landing "
        << num_land_refused << std::endl
        << "Total number of planes refused for takeoff "
        << num_takeoff_refused << std::endl
        << "Total number of planes that landed "
        << num_landings << std::endl
        << "Total number of planes that took off "
        << num_takeoffs << std::endl
        << "Total number of planes left in landing queue "
        << landings_size << std::endl
        << "Total number of planes left in takeoff queue "
        << take_off_size << std::endl;
    std::cout << "Percentage of airport idle time "
        << 100.0 * ((( float ) idle_time)/( float ) runways.size()) / (( float ) time) << "%" << std::endl;
    std::cout << "Percentage of idle time per runway:\n";

    for(int i = 0; i<runways.size(); i++){
        std::cout << "Runway#" << i+1 << ": "
                    << 100.0 * (( float )runways[i]->get_idle_time()) / (( float ) time) << "%\n";
    }

    std::cout << "Average wait in landing queue "
        << (( float ) land_wait) / (( float ) num_landings) << " time units";
    std::cout << std::endl << "Average wait in takeoff queue "
        << (( float ) takeoff_wait) / (( float ) num_takeoffs)
        << " time units" << std::endl;
    std::cout << "Average observed rate of planes wanting to land "
        << (( float ) num_land_requests) / (( float ) time)
        << " per time unit" << std::endl;
    std::cout << "Average observed rate of planes wanting to take off "
        << (( float ) num_takeoff_requests) / (( float ) time)
        << " per time unit" << std::endl;
}