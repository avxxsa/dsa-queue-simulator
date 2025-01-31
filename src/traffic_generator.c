#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/queue.h"

// Function to randomly generate vehicles and add them to queues
void generateTraffic(Queue* laneA, Queue* laneB, Queue* laneC, Queue* laneD, int numVehicles) {
    srand(time(NULL)); // Seed for random numbers

    for (int i = 0; i < numVehicles; i++) {
        int lane = rand() % 4;  // Randomly choose a lane (0 to 3)
        int vehicleID = 1000 + i; // Assign a unique vehicle ID

        switch (lane) {
            case 0: enqueue(laneA, vehicleID); break;
            case 1: enqueue(laneB, vehicleID); break;
            case 2: enqueue(laneC, vehicleID); break;
            case 3: enqueue(laneD, vehicleID); break;
        }
    }
}

// Testing the traffic generator
int main() {
    Queue* laneA = createQueue();
    Queue* laneB = createQueue();
    Queue* laneC = createQueue();
    Queue* laneD = createQueue();

    printf("Generating traffic...\n");
    generateTraffic(laneA, laneB, laneC, laneD, 10); // Generate 10 vehicles

    printf("Lane A: "); displayQueue(laneA);
    printf("Lane B: "); displayQueue(laneB);
    printf("Lane C: "); displayQueue(laneC);
    printf("Lane D: "); displayQueue(laneD);

    return 0;
}