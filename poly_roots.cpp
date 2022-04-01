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

int s = 3;
int t = 5;
const unsigned int SIZE = pow(2,s);

const unsigned int prim_poly_3 = 0b011;
const unsigned int prim_poly_8 = 0b00011101;
const unsigned int prim_poly_9 = 0b000010001;
const unsigned int prim_poly_15 = 0b000000000000011;
const unsigned int prim_poly_16 = 0b0000001111011101;
const unsigned int prim_poly_17 = 0b00000000000001001;
const unsigned int prim_poly_18 = 0b000000000000111111;
const unsigned int prim_poly_19 = 0b0000000000000100111;
const unsigned int prim_poly_20 = 0b00000000000000001001;
const unsigned int prim_poly_21 = 0b000000000000000000101;
const unsigned int prim_poly_22 = 0b0000000000000000000011;
const unsigned int prim_poly_23 = 0b00000000000000000100001;
const unsigned int prim_poly_24 = 0b000000000000000010000111;
const unsigned int prim_poly_25 = 0b0000000000000000000001001;

void build_finite_field(unsigned int size, Long *finite_field, unsigned int prim_poly){
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

void sort_finite_field(Long *finite_field, const unsigned int size){
    int swap, tmp;

    do{
        swap = 0;
        for(int i = 0; i < (size-1) ; i++){
            if(finite_field[i] > finite_field[i+1]){
                tmp = finite_field[i];
                finite_field[i] = finite_field[i+1];
                finite_field[i+1] = tmp;

                swap = 1;
            }
        }
    }while(swap);

    return;
}

int is_root(Poly<Long> f, Long a, unsigned int mod){
    unsigned int image = f(a);
    if(image >= SIZE){
        image &= SIZE-1;
        image ^= mod;
    }

    return (image == 0);
}

Long count_roots(Poly<Long> f, Long *field, unsigned int alpha_m){
    Long freq_c = 0;

    for(int i = 0; i < SIZE ; i++){
        if(is_root(f,field[i], alpha_m)){
            freq_c++;
        }
    }

    return freq_c;
}

Long projective_points(Poly<Long> f, Long *field, unsigned int prim_poly){
    std::vector<int> freq_arr ;
    Long freq_c = 0;
    Long N_p = 0;

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

Long rational_points(Poly<Long> f, Long *field, unsigned int prim_poly){
    int delta;
    if((f.deg()%4) == 1){
        delta = 1;
    }
    else if((f.deg()%4) == 3){
        delta = 0;
    }

    Long freq_0 = count_roots(f, field, prim_poly);
    Long N_p = projective_points(f, field, prim_poly);

    return (N_p+(3*freq_0)+delta);
}

int main(){

    unsigned int prim_poly = prim_poly_3;
    Long finite_field[SIZE] = {};

    build_finite_field(SIZE, finite_field, prim_poly);
    sort_finite_field(finite_field, SIZE);

    for(int i = 0; i < SIZE ; i++){
        printf("%lld\n", finite_field[i]);
    }

    Long a = finite_field[5];
    Long b = finite_field[7];
    Long prod = (finite_field[5]<<0)^finite_field[7];
    if(prod >= SIZE){
        prod &= SIZE-1;
        prod ^= prim_poly;
    }
    printf("%lld * %lld = %lld\n", a,b, prod);

    //Long a, b, prod;
    //for(int i = 0; i < SIZE ; i++){
        //for(int j = 0; j < SIZE ; j++){
            //a = finite_field[i];
            //b = finite_field[j];
            //prod = finite_field[i] * finite_field[j];
            //if(prod >= SIZE){
                //prod &= SIZE-1;
                //prod ^= prim_poly;
            //}
            //printf("%lld * %lld = %lld\n", a,b, prod);
        //}
        //printf("\n");
    //}

    //Long coef_f[t+1];
    //Long coef_g[2] = {1,1};

    //for(int i = 0; i < t ; i++){
        //coef_f[i] = 0;
    //}
    //coef_f[t] = 1;

    //Poly<Long> f(t, coef_f);

    //Poly<Long> g(1, coef_g);
    //g ^= t;
    //g += f;
    //g %= 2;

    //Poly<Long> h = g;
    //for(int i = 0; i < SIZE ; i++){
        //h -= finite_field[i];
        ////for(int i = 0; i <= h.deg() ; i++){
            ////printf("%lldx^%lld\t", h[i], i);
        ////}

        //printf("feq_%lld(g(x)) = %lld\n", i, count_roots(g,finite_field, prim_poly_8));

        //h = g;
    //}

    //int N_p = projective_points(g,finite_field, prim_poly_8);
    //printf("N_p(g(x)) = %d\n", N_p);

    //int N_s = rational_points(g, finite_field, prim_poly_8);
    //printf("N_s(g(x)) = %d\n", N_s);

    return 0;
}
