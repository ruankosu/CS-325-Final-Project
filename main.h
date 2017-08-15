#ifndef MAIN_H
#define MAIN_H

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <climits>
#include <ctime>
#include <cmath>
#include <fstream>
#include <sstream>

#include "city.h"
#include "cities.h"
#include "tour.h"
#include "branch-and-bound.h"

using namespace std;

void setFileCities(class Cities *cities, string filename);
void setRandomCities(class Cities *cities, int limit);
void setCitiesBaseCase(class Cities *cities);

void setRandomTour(class Tour *tour, int limit);
void setTourBaseCase(class Tour *tour);

#endif
