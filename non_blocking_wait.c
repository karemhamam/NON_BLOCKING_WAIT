#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include "non_blocking_wait.h"

/**
 * @file non_blocking_wait.c
 * @brief Implements a non-blocking wait alternative to handle child process termination.
 * 
 * This file contains the implementation of the non-blocking wait logic. It uses 
 * the `waitpid()` function with the `WNOHANG` option to check for terminated child
 * processes without blocking the parent process. It also handles the cleaning up 
 * of terminated child processes to avoid zombie processes.
 */

/**
 * @brief Handles terminated child processes in a non-blocking manner.
 * 
 * This function uses `waitpid()` with the `WNOHANG` option to avoid blocking
 * the parent process. It checks for terminated children and prints their
 * PID, exit status, and termination reason (normal exit or signal).
 */
void handle_terminated_children() {
    pid_t pid;
    int status;

    // Non-blocking wait on child processes
    while ((pid = waitpid(-1, &status, WNOHANG)) > 0) {
        // Check if the child process terminated normally
        if (WIFEXITED(status)) {
            printf("Child PID %d terminated normally with exit status %d\n", pid, WEXITSTATUS(status));
        }
        // Check if the child process terminated by a signal
        else if (WIFSIGNALED(status)) {
            printf("Child PID %d terminated by signal %d\n", pid, WTERMSIG(status));
        }
        // Handle other termination states if necessary
    }
}
