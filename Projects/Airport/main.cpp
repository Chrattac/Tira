#include "header.h"

int main()     //  Airport simulation program
/*
Pre:  The user must supply the number of time intervals the simulation is to
      run, the expected number of planes arriving, the expected number
      of planes departing per time interval, and the
      maximum allowed size for runway queues.
Post: The program performs a random simulation of the airport, showing
      the status of the runway at each time interval, and prints out a
      summary of airport operation at the conclusion.
Uses: Classes Runway, Plane, Random and functions run_idle, initialize.
*/

{
   int end_time;            //  time to run simulation
   int queue_limit;         //  size of Runway queues
   int runway_count;        //  amount of runways
   double arrival_rate, departure_rate;

   initialize(end_time, queue_limit, arrival_rate, departure_rate, runway_count);
   //simulate_small_runaway(end_time, queue_limit, arrival_rate, departure_rate);

   simulate_several_runaways(end_time, queue_limit, arrival_rate, departure_rate, runway_count);




   return EXIT_SUCCESS;
}

