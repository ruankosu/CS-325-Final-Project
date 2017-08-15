#ifndef TOUR_H
#define TOUR_H

using namespace std;

class Tour {
    private:
        vector<pair<class City *, class City *> > route;      // A vector of containing the route of the Tour

    public:
        Tour() {  }
        ~Tour() {
            // cout << "DESTORYING TOUR" << '\n';
            if (route.size() > 0) { clear(); }
        }

        vector<pair<class City *, class City *> > * getRoute() { return &route; }

        const int * getIdentifier(int idx, int child) {
            if (child == 0) {
                return route.at(idx).first->getIdentifier();
            } else {
                return route.at(idx).second->getIdentifier();
            }
        }

        const pair<int,int> * getCoordinates(int idx, int child) {
            if (child == 0) {
                return route.at(idx).first->getCoordinates();
            } else {
                return route.at(idx).second->getCoordinates();
            }
        }

        int distance(class City *origin, class City *destination){
            int sub_distance = 0, xs_sqaured = 0, ys_sqaured = 0;

            const pair<int,int> *originCoord = origin->getCoordinates();
            const pair<int,int> *destinationCoord = destination->getCoordinates();

            xs_sqaured = pow((originCoord->first - destinationCoord->first), 2);
            ys_sqaured = pow((originCoord->second - destinationCoord->second), 2);

            return sub_distance = round( sqrt( (xs_sqaured + ys_sqaured) ) );
        }

        int distance(){
            int total_distance = 0;

            for (int idx = 0; idx < route.size(); idx++) {
                total_distance += route.at(idx).first->distanceTo(route.at(idx).second);
            }

            return total_distance;
        }

        void push_back(vector<int> *first, vector<int> *second) {
            class City *origin = new class City(first);
            class City *destination = new class City(second);

            pair<class City *, class City*> group = pair<class City *, class City*> (
                origin,
                destination
            );

            route.push_back(group);

        }

        void push_back(class City *origin, class City *destination) {

            pair<class City *, class City*> group = pair<class City *, class City*> (
                origin,
                destination
            );

            route.push_back(group);

        }

        void print() {
            for (int idx = 0; idx < route.size(); idx++) {
            route.at(idx).first->print();
                cout << " to ";
                route.at(idx).second->print();
                cout << '\n';
            }
        }

        void clear() {
            for (int idx = route.size() - 1; idx >= 0; idx--) {
                if (route.at(idx).first) { delete route.at(idx).first; }
                if (route.at(idx).second) { delete route.at(idx).second; }
            }
        }

};

#endif
