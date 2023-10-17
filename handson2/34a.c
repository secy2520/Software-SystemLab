/*
--------------------------------------------------------
--------------------------------------------------------

Name - 34a.c
Author - Jass Sadana
Description - Write a program to implement concurrent server using pthread_create.


--------------------------------------------------------
--------------------------------------------------------
*/















#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>
#include<stdbool.h>
#include<string.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

void *handleClient(void *arg);

int main() 
  {
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddress, clientAddress;
    socklen_t clientAddrLen = sizeof(clientAddress);

    // Create a socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) 
    {
        perror("Socket creation failed");
        exit(1);
    }

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(PORT);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket
    if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) 
    {
        perror("Socket binding failed");
        exit(1);
    }

    // Listen for incoming client connections
    if (listen(serverSocket, MAX_CLIENTS) == -1)
    {
        perror("Listening failed");
        exit(1);
    }

    printf("Server is listening on port %d...\n", PORT);

    // Accept and handle client connections
    while (1)
{
      clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientAddrLen);
        if (clientSocket == -1) {
            perror("Accepting connection failed");
            continue;
        }

        int childPID = fork();
        if (childPID == -1) {
            perror("Fork failed");
            close(clientSocket);
        } else if (childPID == 0) {
            // This is the child process
            close(serverSocket); // Close the server socket in the child process
            handleClient(clientSocket);
            close(clientSocket); // Close the client socket in the child process
            exit(0);
        } else {
            // This is the parent process
            close(clientSocket); // Close the client socket in the parent process
   }

    close(serverSocket);

    return 0;
}

void *handleClient(void *arg)
 {
    int clientSocket = *((int *)arg);
    char buffer[BUFFER_SIZE];

    send(clientSocket,"Hi", strlen("Hi"),0);
    // Receive and process data from the client
    while (1) {
        int bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesRead <= 0) 
          {
            close(clientSocket);
            pthread_exit(NULL);
          }
         buffer[bytesRead] = '\0';

        // Process the received data based on client role
      if (strstr(buffer, "hello") != NULL) 
         {
                  send(clientSocket,"Thank you", strlen("Thank you"),0);
        } 
   
 
}
    pthread_exit(NULL);
}
