#ifndef NON_BLOCKING_WAIT_H
#define NON_BLOCKING_WAIT_H

/**
 * @file non_blocking_wait.h
 * @brief Header file for the non-blocking wait implementation.
 * 
 * This file declares functions for handling terminated child processes
 * in a non-blocking manner. The main function checks for terminated 
 * children and ensures none of them become zombie processes.
 */

/**
 * @brief Handles terminated child processes in a non-blocking manner.
 * 
 * This function uses `waitpid()` with the `WNOHANG` option to avoid blocking
 * the parent process. It checks for terminated children and prints their
 * PID, exit status, and termination reason (normal exit or signal).
 * 
 * @return void
 */
void handle_terminated_children(void);

#endif // NON_BLOCKING_WAIT_H
