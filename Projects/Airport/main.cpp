#include "header.h"

int main()     //  Airport simulation program

{
   int end_time;            //  time to run simulation
   int queue_limit;         //  size of Runway queues
   int runway_count;        //  amount of runways
   double arrival_rate, departure_rate;

   initialize(end_time, queue_limit, arrival_rate, departure_rate, runway_count);
   //simulate_small_runaway(end_time, queue_limit, arrival_rate, departure_rate);

   start_simulation(end_time, queue_limit, arrival_rate, departure_rate, runway_count);




   return EXIT_SUCCESS;
}

