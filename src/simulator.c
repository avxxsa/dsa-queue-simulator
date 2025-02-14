#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "../include/queue.h"

#define FILE_NAME "vehicles.data"

Queue* laneA;
Queue* laneB;
Queue* laneC;
Queue* laneD;

// Function to read vehicles from the file and add them to queues
void* readTrafficData(void* arg) {
    FILE* file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("Error: Unable to open %s for reading.\n", FILE_NAME);
        return NULL;
    }

    int vehicleID, lane;
    while (fscanf(file, "%d %d", &vehicleID, &lane) != EOF) {
        switch (lane) {
            case 0: enqueue(laneA, vehicleID); break;
            case 1: enqueue(laneB, vehicleID); break;
            case 2: enqueue(laneC, vehicleID); break;
            case 3: enqueue(laneD, vehicleID); break;
        }
    }

    fclose(file);
    printf("Loaded traffic data from %s.\n", FILE_NAME);
    return NULL;
}

// Function to process the queue and simulate vehicle movement
void* processTraffic(void* arg) {
    for (int i = 0; i < 5; i++) {
        printf("\nProcessing Traffic...\n");

        if (!isQueueEmpty(laneA)) printf("Vehicle %d passed from Lane A\n", dequeue(laneA));
        if (!isQueueEmpty(laneB)) printf("Vehicle %d passed from Lane B\n", dequeue(laneB));
        if (!isQueueEmpty(laneC)) printf("Vehicle %d passed from Lane C\n", dequeue(laneC));
        if (!isQueueEmpty(laneD)) printf("Vehicle %d passed from Lane D\n", dequeue(laneD));

        sleep(1); // Simulate delay between cycles
    }
    return NULL;
}

int main() {
    // Initialize queues
    laneA = createQueue();
    laneB = createQueue();
    laneC = createQueue();
    laneD = createQueue();

    // Create threads
    pthread_t fileReaderThread, trafficProcessorThread;
    pthread_create(&fileReaderThread, NULL, readTrafficData, NULL);
    pthread_join(fileReaderThread, NULL); // Wait for file reading to finish

    pthread_create(&trafficProcessorThread, NULL, processTraffic, NULL);
    pthread_join(trafficProcessorThread, NULL);

    return 0;
}