#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/queue.h"

void generateTraffic(int numVehicles) {
    srand(time(NULL)); // Seed for random numbers

    // Open files for writing
    FILE* fileA = fopen("laneA.txt", "w");
    FILE* fileB = fopen("laneB.txt", "w");
    FILE* fileC = fopen("laneC.txt", "w");
    FILE* fileD = fopen("laneD.txt", "w");

    if (!fileA || !fileB || !fileC || !fileD) {
        printf("Error opening files!\n");
        return;
    }

    for (int i = 0; i < numVehicles; i++) {
        int lane = rand() % 4;
        int vehicleID = 1000 + i;

        switch (lane) {
            case 0: fprintf(fileA, "%d\n", vehicleID); break;
            case 1: fprintf(fileB, "%d\n", vehicleID); break;
            case 2: fprintf(fileC, "%d\n", vehicleID); break;
            case 3: fprintf(fileD, "%d\n", vehicleID); break;
        }
    }

    fclose(fileA);
    fclose(fileB);
    fclose(fileC);
    fclose(fileD);
}