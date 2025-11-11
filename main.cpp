// COMSC 210 | Lab 32 | 10 NOV 2025
// IDE: VS Code

#include <algorithm>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <string>

#include "Car.h"

using namespace std;

// Constants
const int INIT_SIZE = 2;

// Fn prototypes
int prob();
void printDeque(const deque<Car>& cars);
// -----------------------------
// Main
// -----------------------------
int main() {

    // Set seed
    srand(time(0));

    // Deque of Cars of INIT_SIZE
    deque<Car> cars;
    for (int i = 0; i < INIT_SIZE; i++) {
        cars.push_back(Car());      // EDIT ONCE CAR CLASS IS AVAILABLE
    }
    cout << "Initial queue:" << endl;
    printDeque(cars);

    // Simulation
    while (cars.size() > 0) {

        // 55% chance front car leaves
        // 45% chance new car arrives at end
        prob = prob();

        if (prob <= 55) {
            cout << "Time: 2 Operation: Car paid: [2000 Volkswagen (2408)]" << endl;
            cars.pop_front();           // EDIT ONCE CAR CLASS IS AVAILABLE
        }
    }



    return 0;
}

// -----------------------------
// Functions
// -----------------------------
int prob() {
    // Random int 1-100
    return rand() % 100 + 1;
}

void printDeque(const deque<Car>& cars) {
    // Prints car info (indented)
    for (const Car& car : cars) {
        cout << "\t";
        car.print();        // EDIT ONCE CAR CLASS IS AVAILABLE
    }
    cout << endl;
}