#include "functions.h"

// Functions first:

void initialize(int &end_time, int &queue_limit,
                double &arrival_rate, double &departure_rate, int &runway_count)
/*
Pre:  The user specifies the number of time units in the simulation,
      the maximal queue sizes permitted,
      and the expected arrival and departure rates for the airport.
Post: The program prints instructions and initializes the parameters
      end_time, queue_limit, arrival_rate, and departure_rate to
      the specified values.
Uses: utility function user_says_yes
*/

{
   std::cout << "This program simulates an airport with only one runway." << std::endl
        << "One plane can land or depart in each unit of time." << std::endl;
   std::cout << "Up to what number of planes can be waiting to land "
        << "or take off at any time per runway (max 100)? " << std::flush;
   do{
      queue_limit = get_positive_int();
      if( queue_limit > max_queue ) std::cout << "Max size was 100, try again: " << std::flush;
   }while( queue_limit > max_queue );

   std::cout << "How many units of time will the simulation run? " << std::flush;
   end_time = get_positive_int();
   
   std::cout << "How many runways do you want to use for the simulation? " << std::flush;
   runway_count = get_positive_int();

   bool acceptable;
   do {
      std::cout << "Expected number of arrivals per unit time? " << std::flush;
      std::cin  >> arrival_rate;
      std::cout << "Expected number of departures per unit time? " << std::flush;
     std::cin  >> departure_rate;
      if (arrival_rate < 0.0 || departure_rate < 0.0)
         std::cerr << "These rates must be nonnegative." << std::endl;
      else
         acceptable = true;

      if (acceptable && (arrival_rate + departure_rate) > runway_count)
         std::cerr << "Safety Warning: This airport will become saturated. " << std::endl;

   } while (!acceptable);
}

void run_idle(int time)
/*
Post: The specified time is printed with a message that the runway is idle.
*/
{
   std::cout << time << ": At least one runway is idle." << std::endl;
}


void simulate_several_runaways
(int &end_time, int &queue_limit, 
double &arrival_rate, double &departure_rate, int runway_count)
{
    int flight_number = 0;
    Random variable;
    Queue<Plane, max_queue> planes;
    Airport airport(queue_limit, runway_count);

    for (int current_time = 0; current_time < end_time; current_time++) { //  loop over time intervals
        int number_arrivals = variable.poisson(arrival_rate);  //  current arrival requests
        for (int i = 0; i < number_arrivals; i++) {
           Plane current_plane(flight_number++, current_time, arriving);
           if (airport.can_land(current_plane) != success)
              current_plane.refuse();
        }

        int number_departures= variable.poisson(departure_rate); //  current departure requests
        for (int j = 0; j < number_departures; j++) {
           Plane current_plane(flight_number++, current_time, departing);
           if (airport.can_depart(current_plane) != success)
              current_plane.refuse();
        }

        // Use as many planes as there are runways
        for(int k = 0; k < runway_count; k++) planes.append(Plane());

        bool land, take_off, bool_idle;

        while(!planes.empty()){
            Plane moving_plane;
            planes.retrieve_and_serve(moving_plane);

            airport.activity(current_time, moving_plane, 
                                land, take_off, bool_idle);
            
            if(land) moving_plane.land(current_time);
            else if(take_off) moving_plane.fly(current_time);
            else if(bool_idle) run_idle(current_time);

        }

        airport.reset_runways();
    }
    airport.shut_down(end_time);
}




char get_command()
{
   char command;
   bool waiting = true;

   while (waiting) {
      std::cin >> command;
      command = tolower(command);
      if (command == 'a' || command == 'b' || command == 'd'
         || command == 'x' || command == 'z') waiting = false;
      else {
         std::cout << "\nPlease enter a valid command\n"   << std::endl;
      }
   }
   return command;
}

int get_positive_int(){
   int integer;
   bool obey;

   do{
      std::cin >> integer;
      if(std::cin.fail() || integer < 0){
         std::cout << "Please give positive integer: " << std::flush;
         std::cin.clear();
         std::cin.ignore(100, '\n');
         obey = false;
      }
      else obey = true;
   }while(!obey);


   return integer;
}