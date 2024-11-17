/**
 * File: signal_sigaction
 * Modified by: Eric Mahn
 * 
 * Brief summary of program: Uses sigaction to register a handler for
 * the SIGUSR1 signal. Waits in an infinite loop, and when the SIGUSR1
 * signal is found print the process identifier, then return.
 *
 * How to send SIGUSR1
 * kill -SIGUSR1 <pid>
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig, siginfo_t *info, void *null) {
    //print message
    if(sig == SIGUSR1) {
        printf("Recieved SIGUSR1, Process ID: %d\n", info->si_pid);
    }
    exit(1);
}

int main() {
    //create structure
    struct sigaction sa;

    //set the flags to SIGINFO and set action to handler
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handler;

    //set the signal
    sigaction(SIGUSR1, &sa, NULL);

    //print PID and wait for signal
    printf("Process ID: %d\n", getpid());
    printf("Waiting for SIGUSR1 signal...\n");

    //infinite loop to wait for signal
    while(1) {
        pause();
    }

    return 0;
}