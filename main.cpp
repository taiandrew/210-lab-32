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
const int N_PERIODS = 5;

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

    // Print init queues
    cout << "Initial queues:" << endl;
    printAllLanes(lanes);
    cout << endl;
    
    
    // Simulation
    for (int t = 0; t < N_PERIODS; t++) {

        cout << "Time " << t+1 << endl;

        // For each lane...
        for (int l = 0; l < N_LANES; l++) {
            int pr = prob();

            // If lane empty, 50/50 arrive
            if (pr<=50 && lanes[l].size() == 0) {
                cout << "Lane " << l+1 << " joined: ";
                lanes[l].push_back(Car());
                lanes[l].back().print();
                continue;
            }

            // Leaves
            if (pr <= PR_LEAVE && lanes[l].size() > 0) {
                cout << "Lane " << l+1 << " paid: ";
                lanes[l].at(0).print();
                lanes[l].pop_front();
            }
            // Arrives
            else if (pr <= PR_LEAVE + PR_ARRIVE) {
                cout << "Lane " << l+1 << " joined: ";
                lanes[l].push_back(Car());
                lanes[l].back().print();
            }
            // Switches
            else if (pr <= PR_LEAVE + PR_ARRIVE + PR_SHIFT && lanes[l].size() > 0) {
                cout << "Lane " << l+1 << " switched: ";

                // Find different lane
                int newLane;
                do {
                    newLane = rand() % N_LANES;
                } while (newLane == l);

                // Switch to new lane
                lanes[newLane].push_back(lanes[l].back());
                lanes[l].back().print();
                lanes[l].pop_back();
            }
        }

        // Print all lanes
        printAllLanes(lanes);
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