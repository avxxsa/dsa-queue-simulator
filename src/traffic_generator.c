#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILE_NAME "vehicles.data"

// Function to generate and write vehicle data to a file
void generateTraffic(int numVehicles) {
    srand(time(NULL)); // Seed for random number generation

    // Open vehicles.data for writing
    FILE* file = fopen(FILE_NAME, "w");
    if (!file) {
        printf("Error: Unable to open %s for writing.\n", FILE_NAME);
        return;
    }

    // Generate vehicles and write them to the file
    for (int i = 0; i < numVehicles; i++) {
        int vehicleID = 1000 + i;  // Unique vehicle ID
        int lane = rand() % 4;     // Random lane (0-3)
        fprintf(file, "%d %d\n", vehicleID, lane);
    }

    fclose(file);
    printf("Generated %d vehicles and saved to %s.\n", numVehicles, FILE_NAME);
}

int main() {
    generateTraffic(20); // Generate 20 vehicles
    return 0;
}