/**
 * @file signal_handler.c
 * @brief Sets a signal handler for SIGINT, the handler prints a message and then quits
 */

/**
 * Modified by: Eric Mahn
 * 
 * Brief summary of modifications: The lab wanted us to make it so the
 * signal no longer goes to the handler, and this can be done by
 * replacing the SIGINT with SIGKILL, since that immediately
 * terminates the process. Also prints the pid to easily
 * kill it
 */


#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Signal handler for SIGINT - prints a message and exits
 */
void handle_signal() {
    printf("Received a signal\n");
    exit(1);
}

int main() {

    // Register for the signal
    signal(SIGKILL, handle_signal);

    printf("Process ID: %d\n", getpid());
    // Wait until a signal is received
    while(1) {
        printf("Sleeping\n");
        sleep(1);
    }

    return 0;
}