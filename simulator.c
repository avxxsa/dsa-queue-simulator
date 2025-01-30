#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include "queue.h"
#include "traffic_light.h"

#pragma comment(lib, "ws2_32.lib")

#define PORT 8080
#define BUFFER_SIZE 1024

Queue vehicleQueue;  // Queue for incoming vehicles
TrafficLight light;  // Traffic light object

void processTraffic() {
    if (queueSize(&vehicleQueue) > 10) {
        setLightState(&light, GREEN);  // Priority lane rule
        printf("🚦 Priority Lane Active: Light is GREEN\n");
    } else {
        setLightState(&light, RED);
        printf("🚦 Normal Condition: Light is RED\n");
    }

    while (!isQueueEmpty(&vehicleQueue) && light.state == GREEN) {
        int vehicleId = dequeue(&vehicleQueue);
        printf("🚗 Vehicle %d is passing the junction\n", vehicleId);
        Sleep(1000);  // Simulate time taken for a vehicle to pass
    }

    printf("🚦 Traffic light changed to RED. Vehicles must stop.\n");
}

int main() {
    WSADATA wsa;
    SOCKET server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    initQueue(&vehicleQueue);
    setLightState(&light, RED);  // Start with red light

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0) {
        printf("WSAStartup failed. Error Code: %d\n", WSAGetLastError());
        return 1;
    }

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Socket failed. Error Code: %d\n", WSAGetLastError());
        return 1;
    }

    // Define server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket to port
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) == SOCKET_ERROR) {
        printf("Bind failed. Error Code: %d\n", WSAGetLastError());
        return 1;
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) == SOCKET_ERROR) {
        printf("Listen failed. Error Code: %d\n", WSAGetLastError());
        return 1;
    }

    printf("Simulator is waiting for vehicle data...\n");

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr*)&address, &addrlen)) == INVALID_SOCKET) {
            printf("Accept failed. Error Code: %d\n", WSAGetLastError());
            continue;
        }

        recv(new_socket, buffer, BUFFER_SIZE, 0);
        int vehicleId = atoi(buffer);
        enqueue(&vehicleQueue, vehicleId);
        printf("🚗 Vehicle %d added to queue. Queue size: %d\n", vehicleId, queueSize(&vehicleQueue));

        processTraffic();  // Check light status and allow cars to pass

        closesocket(new_socket);
    }

    closesocket(server_fd);
    WSACleanup();
    return 0;
}

