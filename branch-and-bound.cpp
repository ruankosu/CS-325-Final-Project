#include "branch-and-bound.h"

class Tour branchAndBound(class Cities *cities) {
    class Tour tour;
    class BNB bnb(cities);

    std::cout << "BRANCH AND BOUND METHOD" << '\n';
    bnb.printMap();
    bnb.solve();

    return tour;
}
