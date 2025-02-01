#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "non_blocking_wait.h"

/**
 * @file main.c
 * @brief Demonstrates the use of non-blocking wait for handling child processes.
 * 
 * This file demonstrates how to use the non-blocking wait implementation 
 * to handle child process termination in a non-blocking manner. It creates 
 * multiple child processes and checks for their termination.
 */

int main() {
    pid_t pid;

    // Fork multiple children
    for (int i = 0; i < 5; i++) {
        pid = fork();
        if (pid == 0) {
            // Child process: simulate work and exit
            printf("Child PID %d created\n", getpid());
            sleep(1); // Simulate some work
            exit(100 + i); // Exit with a unique status code
        }
        else if (pid < 0) {
            // Error forking
            perror("Fork failed");
            exit(1);
        }
    }

    // Parent process: continuously check for terminated children
    while (1) {
        // Call non-blocking wait for terminated children
        handle_terminated_children();

        // Simulate the parent doing other work
        sleep(1);
    }

    return 0;
}
