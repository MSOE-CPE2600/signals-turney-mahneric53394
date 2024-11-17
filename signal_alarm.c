/**
 * File: signal_alarm.c
 * Modified by: Eric Mahn
 * 
 * Brief summary of program: Schedules an alarm to be
 * sent after 5 seconds, then prints a message in
 * the signal handler
 */
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler() {
    //print message
    printf("Alarm Recieved!\n");
}

int main() {
    //set signal handler
    signal(SIGALRM, handler);

    //set an alarm
    printf("Setting alarm for 5 seconds\n");
    alarm(5);
    printf("Waiting...\n");
    
    //wait for alarm
    pause();

    return 0;
}