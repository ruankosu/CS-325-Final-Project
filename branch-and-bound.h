#ifndef BRANCH_AND_BOUND_H
#define BRANCH_AND_BOUND_H

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
#include "BNB.h"

using namespace std;

class Tour branchAndBound(class Cities *cities);

#endif
