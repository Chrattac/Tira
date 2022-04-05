#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <time.h>

enum Error_code {
	success, fail, utility_range_error, underflow, overflow, fatal,
	not_present, duplicate_error, entry_inserted, entry_found,
	internal_error
};

// Airport enums for correct order
enum Runway_activity {idle, land, take_off, busy};
enum Runway_purpose {any, arrivals, arrivals_strict, departures, departures_strict};
enum Plane_status {null, arriving, departing};

bool user_says_yes();
