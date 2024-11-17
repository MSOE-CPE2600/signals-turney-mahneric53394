/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by: Eric Mahn
 * 
 * Brief summary of modifications: Made a handler function that handles
 * the segmentation fault. However, causes an infinite loop when the
 * handler doesn't exist, since the process starts at the same spot
 * it was stopped, so it always tries to dereference the null pointer.
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler() {
    printf("ERROR: A segmentation fault occurred\n");
}

int main (int argc, char* argv[]) {
   
    signal(SIGSEGV, handler);
    
    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}