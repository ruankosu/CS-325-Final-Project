#include "BNB.h"

BNB::BNB(class Cities *cities) {
    N = cities->size();
    best_cost = INT_MAX;
    map = new int * [N];
    best_route = new int[N];
    for (int idx = 0; idx < N; idx++) {
        best_route[idx] = INT_MAX;
        map[idx] = new int[N];
        for (int jdx = 0; jdx < N; jdx++) {
            if (idx != jdx) { map[idx][jdx] = cities->at(idx)->distanceTo(cities->at(jdx)); }
        }
    }
}

int BNB::findOptimalByGreedy(unordered_set<int>::iterator idx, unordered_set<int> *location_set) {

}

void BNB::solve() {


}
