#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    #include <windows.h>  // Windows: Sleep()
#else
    #include <unistd.h>   // Linux/Mac: sleep()
#endif

#include "../include/queue.h"
#include "../include/traffic_light.h"
#include "../include/traffic_generator.h"

// Function to simulate traffic at the junction
void runSimulation(Queue* laneA, Queue* laneB, Queue* laneC, Queue* laneD, TrafficLight lights[]) {
    while (1) {
        // Update traffic lights
        updateLights(lights, laneA, laneB, laneC, laneD);
        
        // Display the traffic light state
        printf("\nTraffic Light Status:\n");
        displayLights(lights, 4);
        
        // Let vehicles pass if the lane has GREEN light
        for (int i = 0; i < 4; i++) {
            if (lights[i].state == GREEN) {
                printf("Vehicles passing from Lane %c:\n", 'A' + i);
                for (int j = 0; j < 3 && !isQueueEmpty(i == 0 ? laneA : (i == 1 ? laneB : (i == 2 ? laneC : laneD))); j++) {
                    int vehicle = dequeue(i == 0 ? laneA : (i == 1 ? laneB : (i == 2 ? laneC : laneD)));
                    printf("Vehicle %d has passed.\n", vehicle);
                }
            }
        }
        
        // Wait before updating (simulating time delay)
        #ifdef _WIN32
            Sleep(2000); // Windows: 2 seconds
        #else
            sleep(2); // Linux/Mac: 2 seconds
        #endif
        
        // Stop after a few iterations for testing
        static int iterations = 0;
        iterations++;
        if (iterations >= 5) break;
    }
}

int main() {
    // Create queues for each lane
    Queue* laneA = createQueue();
    Queue* laneB = createQueue();
    Queue* laneC = createQueue();
    Queue* laneD = createQueue();
    
    // Generate vehicles
    generateTraffic(laneA, laneB, laneC, laneD, 20); // Create 20 random vehicles

    // Initialize traffic lights
    TrafficLight lights[4];
    initializeLights(lights, 4);

    // Run the traffic simulation
    runSimulation(laneA, laneB, laneC, laneD, lights);

    return 0;
}