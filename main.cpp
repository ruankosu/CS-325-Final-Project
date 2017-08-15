#include "main.h"

void setFileCities(class Cities *cities, string filename) {

    // File Fill
    ifstream read;
    string line, content;
    string::size_type size;
    vector<int> values;

    read.open(filename);

    while (getline(read, line)) {
        stringstream line_stream(line);
        while(getline(line_stream, content, ' ')) {
            values.push_back(std::stoi(content, &size));
        }
        cities->push_back(&values);
        values.clear();
    };

    read.close();

}

void setRandomCities(class Cities *cities, int limit) {
    vector<int> values;
    // Random Fill
    for (int idx = 0; idx < limit; idx++) {
        values.push_back(idx + 1);
        values.push_back(rand() % 10);
        values.push_back(rand() % 10);

        cities->push_back(&values);
        values.clear();
    }

}

void setCitiesBaseCase(class Cities *cities) {
    // Base Case provided in project description
    vector<int> values;

    values.push_back(0);
    values.push_back(0);
    values.push_back(0);

    cities->push_back(&values);
    values.clear();

    values.push_back(1);
    values.push_back(1);
    values.push_back(3);

    cities->push_back(&values);
    values.clear();

    values.push_back(2);
    values.push_back(6);
    values.push_back(0);

    cities->push_back(&values);
    values.clear();

}

void setRandomTour(class Tour *tour, int limit) {
    // Random Fill
    vector<int> first;
    vector<int> second;

    for (int idx = 0; idx < limit; idx++) {
        if (idx == 0) {
            first.push_back(idx + 1);
            first.push_back(rand() % 10);
            first.push_back(rand() % 10);

            second.push_back(idx + 2);
            second.push_back(rand() % 10);
            second.push_back(rand() % 10);

            tour->push_back(&first, &second);

            first.clear();
            second.clear();

        } else if (idx > 0 && idx < limit - 1){
            first.push_back(*(tour->getIdentifier(idx - 1, 1)));
            first.push_back(tour->getCoordinates(idx - 1, 1)->first);
            first.push_back(tour->getCoordinates(idx - 1, 1)->second);

            second.push_back(idx + 2);
            second.push_back(rand() % 10);
            second.push_back(rand() % 10);

            tour->push_back(&first, &second);

            first.clear();
            second.clear();
        } else {
            first.push_back(*(tour->getIdentifier(idx - 1, 1)));
            first.push_back(tour->getCoordinates(idx - 1, 1)->first);
            first.push_back(tour->getCoordinates(idx - 1, 1)->second);

            second.push_back(*(tour->getIdentifier(0, 0)));
            second.push_back(tour->getCoordinates(0, 0)->first);
            second.push_back(tour->getCoordinates(0, 0)->second);

            tour->push_back(&first, &second);

            first.clear();
            second.clear();
        }
    }

}

void setTourBaseCase(class Tour *tour) {
    // Base Case provided in project description

    vector<int> first;
    vector<int> second;

    first.push_back(1);
    first.push_back(0);
    first.push_back(0);

    second.push_back(2);
    second.push_back(1);
    second.push_back(3);

    tour->push_back(&first, &second);

    first.clear();
    second.clear();

    first.push_back(2);
    first.push_back(1);
    first.push_back(3);

    second.push_back(3);
    second.push_back(6);
    second.push_back(0);

    tour->push_back(&first, &second);

    first.clear();
    second.clear();

    first.push_back(3);
    first.push_back(6);
    first.push_back(0);

    second.push_back(1);
    second.push_back(0);
    second.push_back(0);

    tour->push_back(&first, &second);

    first.clear();
    second.clear();

}

int main(int argc, char const *argv[]) {
    srand(0);

    string cities_file = "cities.txt";

    class Cities cities;
    class Tour test, branchAndBoundTour;

    setFileCities(&cities, cities_file);
    cout << '\n'; cities.print(); cout << '\n';

    branchAndBoundTour = branchAndBound(&cities);
    // std::cout << "RETURNED" << '\n';
    branchAndBoundTour.print();

    setTourBaseCase(&test);
    cout << '\n'; test.print();
    cout << test.distance() << '\n';

    return 0;
}
