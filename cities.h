#ifndef CITIES_H
#define CITIES_H

using namespace std;

class Cities {
    private:
        vector<class City> cities;        // A vector of containing all possible cities

    public:
        Cities() {  }
        ~Cities() {
            // cout << "DESTORYING CITIES" << '\n';
            if (cities.size() > 0) { clear(); }
        }

        vector<class City> * getCities() { return &cities; }
        int size() { return cities.size(); }
        class City * at(int idx) { return &cities.at(idx); }
        void push_back(vector<int> *values) {
            class City city(values);
            cities.push_back(city);
        }

        void print() {
            for (int idx = 0; idx < cities.size(); idx++) {
                cities.at(idx).print(); cout << '\n';
            }
        }

        void clear() {

        }

};

#endif
