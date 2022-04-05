#pragma once

#include "header.h"

class Runway {
public:
    Runway();
    Runway(int limit, Runway_purpose purpose=any);
    virtual Error_code can_land(const Plane &current);
    virtual Error_code can_depart(const Plane &current);
    virtual Runway_activity activity(int time, Plane &moving);

    int get_landings_requests() const;
    int get_landings() const;
    int get_landing_accepted() const;
    int get_landings_refused() const;
    int get_land_wait() const;

    int get_takeoffs_requests() const;
    int get_takeoffs() const;
    int get_takeoffs_accepted() const;
    int get_takeoffs_refused() const;
    int get_takeoff_wait() const;

    int get_idle_time() const;

    bool get_landing_full() const;
    bool get_landing_empty() const;
    int get_landing_size() const;
    

    bool get_takeoff_full() const;
    bool get_takeoff_empty() const;
    int get_takeoff_size() const;

    bool get_landing_priority() const;
    bool get_takeoff_priority() const;

    void set_landing_priority(bool priority);
    void set_takeoff_priority(bool priority);

    bool queues_empty() const;

    Error_code add_landing(const Plane &current);
    Error_code add_takeoff(const Plane &current);

    Error_code remove_landing(Plane &current);
    Error_code remove_takeoff(Plane &current);

    void reset_usage();
    bool get_usage() const;

    Runway_purpose get_purpose() const;

protected:
    Queue<Plane, max_queue> landing;
    Queue<Plane, max_queue> takeoff;
    int queue_limit;
    int num_land_requests;        //  number of planes asking to land
    int num_takeoff_requests;     //  number of planes asking to take off
    int num_landings;             //  number of planes that have landed
    int num_takeoffs;             //  number of planes that have taken off
    int num_land_accepted;        //  number of planes queued to land
    int num_takeoff_accepted;     //  number of planes queued to take off
    int num_land_refused;         //  number of landing planes refused
    int num_takeoff_refused;      //  number of departing planes refused
    int land_wait;                //  total time of planes waiting to land
    int takeoff_wait;             //  total time of planes waiting to take off
    int idle_time;                //  total time runway is idle


private:
    Runway_purpose purpose;       //  purpose of the runway
    bool in_use;
    int idle_check_time;          // to avoid duplicated idle_time -counting
    bool landing_priority = false; // priorities, default is false;
    bool takeoff_priority = false; 

};

class Airport : public Runway{
    public: 
    Airport(int limit, uint8_t runway_count);
    Airport(const Airport&) = delete; //No copying allowed
    ~Airport();

    Error_code can_land (const Plane&current);
    Error_code can_depart (const Plane &current);
    Error_code temporary_runway_use(Runway *runway);

    void reset_runways();
    void activity(int time, Plane &moving, bool& landing, bool& takeoff, bool& idle);
    void shut_down(int time);

    private:
    std::vector<Runway*> runways;
    int take_off_size = 0;
    int landings_size = 0;

};
