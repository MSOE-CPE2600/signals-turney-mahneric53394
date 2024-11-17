/**
 * File: recv_signal.c
 * Modified by: Eric Mahn
 * 
 * Brief summary of program: Uses sigaction to register a handler for
 * the SIGUSR1 signal. Waits in an infinite loop, and when the SIGUSR1
 * signal is found print the sival_int value, then return.
 *
 * How to send SIGUSR1
 * kill -SIGUSR1 <pid>
 *
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig, siginfo_t *info, void *null) {
    //print sival_int value
    if(sig == SIGUSR1) {
        printf("Recieved SIGUSR1 data: %d\n", info->si_value.sival_int);
    }
    exit(1);
}
int main() {
    //create structure
    struct sigaction sa;

    //set the flags to SIGINFO and set action to handler
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handler;

    //sigemptyset(&sa.sa_mask);

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