#ifndef BNB_H
#define BNB_H

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
#include <unordered_set>

#include "city.h"
#include "cities.h"
#include "tour.h"

using namespace std;

class BNB {
    private:
        int N;
        int **map;
        int best_cost;
        int *best_route;

    public:
        BNB() {  }
        BNB(class Cities *cities);
        ~BNB() {
            // std::cout << "DESTROY BNB" << '\n';
            if (map) {
                for (int idx = 0; idx < N; idx++) {
                    if (map[idx]) { delete map[idx]; }
                }
                delete map;
            }
            if (best_route) { delete best_route; }
        }

        int ** getMap() { return map; }

        void solve();
        int findOptimalByGreedy(unordered_set<int>::iterator idx, unordered_set<int> *location_set);

        void printMap() {
            for (int idx = 0; idx < N; idx++) {
                for (int jdx = 0; jdx < N; jdx++) {
                    cout << map[idx][jdx] << " ";
                }
                cout << '\n';
            }
        }

        void printBestRoute() {
            for (int idx = 0; idx < N; idx++) {
                cout << best_route[idx] << '\n';
            }
        }

};

#endif
