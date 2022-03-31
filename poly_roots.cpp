#include<stdio.h>
#include<vector>
#include"polynomial.h"

typedef long long Long;

int pow(int x, int n){
    if(n == 0){
        return 1;
    }
    if(n == 1){
        return x;
    }

    return x*pow(x,n-1);
}

int s = 8;
int t = 7;
const unsigned int SIZE = pow(2,s);

const unsigned int prim_poly_8 = 0b00011101;
//const unsigned int prim_poly_9 = 0b000000000;
const unsigned int prim_poly_15 = 0b0000000000000011;
const unsigned int prim_poly_25 = 0b0000000000000000000001001;

void build_finite_field(unsigned int size, unsigned long long *finite_field, unsigned int prim_poly){
    unsigned int shift_out, keep;

    shift_out = size;
    keep = shift_out-1;

    finite_field[0] = 1;
    for(unsigned int i = 1; i < keep ; i++){
        finite_field[i] = finite_field[i-1]<<1;
        if(finite_field[i] >= shift_out){
            finite_field[i] &= keep;
            finite_field[i] ^= prim_poly;
        }
    }

    return;
}

int is_root(Poly<Long> f, unsigned int a, unsigned int mod){
    unsigned int image = f(a);
    if(image >= SIZE){
        image &= SIZE-1;
        image ^= mod;
    }

    return (image == 0);
}

int count_roots(Poly<Long> f, unsigned long long *field, unsigned int alpha_m){
    int freq_c = 0;

    for(int i = 0; i < SIZE ; i++){
        if(is_root(f,field[i], alpha_m)){
            freq_c++;
        }
    }

    return freq_c;
}

int projective_points(Poly<Long> f, unsigned long long *field, unsigned int prim_poly){
    std::vector<int> freq_arr ;
    int freq_c = 0;
    int N_p = 0;

    Poly<Long> g = f;

    for(int i = 0; i < SIZE ; i++){
        g -= field[i];

        freq_c = count_roots(g, field, prim_poly);
        freq_arr.push_back(freq_c);

        g = f;
    }

    for(int i = 0; i < freq_arr.size() ; i++){
        N_p += freq_arr[i]*freq_arr[i];
    }
    N_p -= pow(2,s+1);

    return N_p;
}

int main(){

    unsigned long long finite_field[SIZE] = {};

    build_finite_field(SIZE, finite_field, prim_poly_8);

    Long coef_f[t+1];
    Long coef_g[2] = {1,1};

    for(int i = 0; i < t ; i++){
        coef_f[i] = 0;
    }
    coef_f[t] = 1;

    Poly<Long> f(t, coef_f);

    Poly<Long> g(1, coef_g);
    g ^= t;
    g += f;
    g %= 2;

    for(int i = 0; i < SIZE ; i++){
        printf("g(%d) == 0\t%d\n", finite_field[i], is_root(g,finite_field[i], prim_poly_8));
    }

    int N_p = projective_points(g, finite_field, prim_poly_8);
    printf("N_p(g) = %d", N_p);

    return 0;
}
