/*
 * Test program for lfsr.h
 * */
#include"lfsr.h"
#include<stdio.h>

const int SIZE = 7;

int main(){

    // Initial state given to the lfsr.
    int state = 0b0001;

    // Store the output of the lfst here.
    int output[20] = {};

    // Call the lfsr on state with period 20, and store it into output.
    lfsr(state, output, 20);

    // print the output stream of the lfsr.
    for(int i = 0; i < 20 ; i++){
        printf("%b", output[i]);
    }
    printf("\n");

    return 0;
}
