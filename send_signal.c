/**
 * File: send_signal.c
 * Modified by: Eric Mahn
 * 
 * Brief summary of program: Sends the SIGUSR1 signal along
 * with a random integer to the sigqueue system call. Print
 * the number before sending the signal.
 */

 #define _GNU_SOURCE
 #include <stdio.h>
 #include <stdlib.h>
 #include <signal.h>
 #include <unistd.h>
 #include <time.h>


int main(int argc, char* argv[]) {
    //make sure command line arguments are valid
    if(argc != 2) {
        printf("Incorrect command line arguments\n");
        exit(1);
    }

    //get the pid value from the command line
    pid_t pid = atoi(argv[1]);
    if (pid <= 0) {
        printf("Invalid PID value\n");
        exit(1);
    }

    //get the random number
    srand(time(NULL));
    int random = rand();

    printf("Sending SIGUSR1 signal with value %d to the process %d\n", random, pid);

    //create the union and set the sival_int to the random number
    union sigval val;
    val.sival_int = random;

    //use the sigqueue function call to send the signal
    sigqueue(pid, SIGUSR1, val);
    
    printf("Signal was sent successfully!\n");
    return 0;

}