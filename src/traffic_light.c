#include <stdio.h>
#include "../include/traffic_light.h"

// Function to initialize traffic lights (all start as RED)
void initializeLights(TrafficLight lights[], int size) {
    for (int i = 0; i < size; i++) {
        lights[i].state = RED;
        lights[i].lane_id = i;
    }
}

// Function to update traffic lights based on queue size
void updateLights(TrafficLight lights[], Queue* laneA, Queue* laneB, Queue* laneC, Queue* laneD) {
    // Priority rule: If Lane A (AL2) has more than 10 vehicles, it gets priority
    if (laneA->size > 10) {
        for (int i = 0; i < 4; i++) {
            lights[i].state = RED;
        }
        lights[0].state = GREEN; // Lane A gets the green light
        return;
    }

    // Normal rotation: Only one lane is green at a time
    static int currentLane = 0; // Start with lane A

    for (int i = 0; i < 4; i++) {
        lights[i].state = RED;
    }
    
    lights[currentLane].state = GREEN;
    currentLane = (currentLane + 1) % 4; // Move to next lane in sequence
}

// Function to display traffic light states
void displayLights(TrafficLight lights[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Lane %c: %s\n", 'A' + i, (lights[i].state == GREEN) ? "GREEN" : "RED");
    }
}