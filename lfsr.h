// A linear feedback shift register
// arg 1: initial state sequence (represented in binary)
// arg 2: Array in which to store the output.
// arg 3: The period of the lfsr
// return value: The ouput array in which the computed bits were stored.
// Additional notes: The period of the lfsr shouldbe known before hand; if not,
// one may introduce an abritrary integer and find the period by counting where
// the bitstream of the output repeats.
int *lfsr(int state, int *output, int size){
    for(int i = 0; i < size  ; i++){
        // extract the significant bit and store it into output.
        int outbit = state & 1;
        output[size-1-i] = outbit;

        // Compute the feedback bit.
        // One can change this rule accordingly to construct different types of
        // lfsrs.
        int feedback = (outbit) ^ ((state >> 2) & 1) ^ ((state >> 3) & 1);

        // shift the state 1 over to the left.
        state >>= 1;

        // right shift the feedback to the least significant bit and store it
        // in the least significant bit of the state.
        state ^= feedback << 3;
    }

    return output;
}
