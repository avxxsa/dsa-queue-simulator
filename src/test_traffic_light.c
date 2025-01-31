#include <stdio.h>
#include "../include/queue.h"
#include "../include/traffic_light.h"

int main() {
    Queue* laneA = createQueue();
    Queue* laneB = createQueue();
    Queue* laneC = createQueue();
    Queue* laneD = createQueue();

    TrafficLight lights[4]; // Four lanes
    initializeLights(lights, 4);

    printf("Initial traffic light state:\n");
    displayLights(lights, 4);

    printf("\nAdding vehicles to Lane A (Priority Lane)...\n");
    for (int i = 0; i < 12; i++) {
        enqueue(laneA, 1000 + i);
    }

    updateLights(lights, laneA, laneB, laneC, laneD);
    printf("\nUpdated traffic light state:\n");
    displayLights(lights, 4);

    return 0;
}