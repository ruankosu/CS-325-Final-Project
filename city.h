#ifndef CITY_H
#define CITY_H

using namespace std;

class City {
    private:
        int identifier;                 // A number indicating the city
        pair<int, int> coordinates;     // A pair containing the longitude and latitude (x,y)

    public:
        City() {
            identifier = INT_MAX;
            coordinates = pair<int, int> (
                INT_MAX,
                INT_MAX
            );
        }

        City(vector<int> *values) {
            identifier = values->at(0);
            coordinates = pair<int, int> (
                values->at(1),
                values->at(2)
            );
        }

        ~City() {  }

        const int * getIdentifier() { return &identifier; }
        const pair<int, int> * getCoordinates() { return &coordinates; }

        int distanceTo(class City *destination){
            int sub_distance = 0, xs_sqaured = 0, ys_sqaured = 0;

            const pair<int,int> *destinationCoord = destination->getCoordinates();

            xs_sqaured = pow((coordinates.first - destinationCoord->first), 2);
            ys_sqaured = pow((coordinates.second - destinationCoord->second), 2);

            return sub_distance = round( sqrt( (xs_sqaured + ys_sqaured) ) );
        }

        void print() { cout << "CITY " << identifier << " @ " << coordinates.first << " " << coordinates.second; };

};

#endif
