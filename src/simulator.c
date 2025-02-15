#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <SDL2/SDL.h>
#include "../include/queue.h"

#define FILE_NAME "vehicles.data"

Queue* laneA;
Queue* laneB;
Queue* laneC;
Queue* laneD;
SDL_Renderer* renderer;
SDL_Window* window;

// Function to read traffic data from the file
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

// Function to process and render traffic movement
void* processTraffic(void* arg) {
    for (int i = 0; i < 5; i++) {
        printf("\nProcessing Traffic...\n");

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Clear screen
        SDL_RenderClear(renderer);

        if (!isQueueEmpty(laneA)) {
            int vehicle = dequeue(laneA);
            printf("Vehicle %d passed from Lane A\n", vehicle);
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            SDL_Rect car = {50, 100, 50, 20};
            SDL_RenderFillRect(renderer, &car);
        }
        if (!isQueueEmpty(laneB)) {
            int vehicle = dequeue(laneB);
            printf("Vehicle %d passed from Lane B\n", vehicle);
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            SDL_Rect car = {150, 100, 50, 20};
            SDL_RenderFillRect(renderer, &car);
        }
        if (!isQueueEmpty(laneC)) {
            int vehicle = dequeue(laneC);
            printf("Vehicle %d passed from Lane C\n", vehicle);
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
            SDL_Rect car = {250, 100, 50, 20};
            SDL_RenderFillRect(renderer, &car);
        }
        if (!isQueueEmpty(laneD)) {
            int vehicle = dequeue(laneD);
            printf("Vehicle %d passed from Lane D\n", vehicle);
            SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
            SDL_Rect car = {350, 100, 50, 20};
            SDL_RenderFillRect(renderer, &car);
        }

        SDL_RenderPresent(renderer);
        sleep(1); // Simulate delay
    }
    return NULL;
}

// Function to initialize SDL2
void initSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }
    window = SDL_CreateWindow("Traffic Simulator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 400, 200, SDL_WINDOW_SHOWN);
    if (!window) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }
}

// Function to clean up SDL2
void cleanupSDL() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main(int argc, char* argv[]) {
    // Initialize queues
    laneA = createQueue();
    laneB = createQueue();
    laneC = createQueue();
    laneD = createQueue();

    // Initialize SDL2
    initSDL();

    // Create threads
    pthread_t fileReaderThread, trafficProcessorThread;
    pthread_create(&fileReaderThread, NULL, readTrafficData, NULL);
    pthread_join(fileReaderThread, NULL);

    pthread_create(&trafficProcessorThread, NULL, processTraffic, NULL);
    pthread_join(trafficProcessorThread, NULL);

    sleep(2); // Keep window open for a moment
    cleanupSDL();
    return 0;
}