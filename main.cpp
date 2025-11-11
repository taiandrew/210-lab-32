// COMSC 210 | Lab 32 | 10 NOV 2025
// IDE: VS Code

#include <algorithm>
#include <array>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <string>

#include "Car.h"

using namespace std;

// Constants
const int INIT_SIZE = 2;
const int N_LANES = 4;

const int PR_LEAVE = 46;
const int PR_ARRIVE = 39;
const int PR_SHIFT = 15;


// Fn prototypes
int prob();
void printDeque(deque<Car>& cars);
void printAllLanes(array<deque<Car>, N_LANES>& lanes);
void testDriver(array<deque<Car>, N_LANES> lanes);

// -----------------------------
// Main
// -----------------------------
int main() {

    // Set seed
    srand(time(0));

    // Initialize N_LANES array of deques
    array<deque<Car>, N_LANES> lanes;
    //testDriver(lanes);
    for (int i = 0; i < N_LANES; i++) {
        // Deque of Cars of INIT_SIZE
        for (int j = 0; j < INIT_SIZE; j++) {
            lanes[i].push_back(Car());
        }
    }
    cout << "Initial queues:" << endl;
    printAllLanes(lanes);
    cout << endl;
    
    /*
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
    */
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

void printAllLanes(array<deque<Car>, N_LANES>& lanes) {
    for (int i = 0; i < N_LANES; i++) {
        cout << "Lane " << i+1 << " Queue:" << endl;
        printDeque(lanes[i]);
    }
}

void testDriver(array<deque<Car>, N_LANES> lanes) {
    // Test function for debugging

    printAllLanes(lanes);

    // Add one car to lane 2
    cout << "Adding car to lane 2:" << endl;
    lanes[1].push_back(Car());
    printAllLanes(lanes);
}