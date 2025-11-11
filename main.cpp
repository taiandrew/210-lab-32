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
const int PR_CUTOFF = 55;
const int N_LANES = 4;

// Fn prototypes
int prob();
void printDeque(deque<Car>& cars);

// -----------------------------
// Main
// -----------------------------
int main() {

    // Set seed
    srand(time(0));

    // Deque of Cars of INIT_SIZE
    deque<Car> cars;
    for (int i = 0; i < INIT_SIZE; i++) {
        cars.push_back(Car());
    }
    cout << "Initial queue:" << endl;
    printDeque(cars);
    cout << endl;
    
    // Simulation
    int t = 1;
    while (cars.size() > 0) {

        t++;
        int pr = prob();

        if (pr <= PR_CUTOFF) {
            // Print front car and pop
            cout << "Time " << t << " Operation: Car paid: ";
            cars.at(0).print();
            cars.pop_front();

        }
        else {
            // Add car to the end and print
            cout << "Time " << t << " Operation: New car arrived:";
            cars.push_back(Car());
            cars.back().print();
            cout << endl;
        }

        // Print current queue
        cout << "Queue:" << endl;
        printDeque(cars);
        cout << endl;
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

void printDeque(deque<Car>& cars) {
    // Prints car info (indented)

    // If list is empty
    if (cars.size() == 0) {
        cout << "\tEmpty" << endl;
        return;
    }

    // Print each car
    for (size_t i = 0; i < cars.size(); i++) {
        cout << "\t";
        cars.at(i).print();
    }
}