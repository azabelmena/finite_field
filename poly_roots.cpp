#include<stdio.h>
#include"polynomial.h"

typedef long long Long;

Long t = 5;
Long s = 5;

Long pow(Long x, Long n){
    if(n == 0){
        return 1;
    }
    if(n == 1){
        return x;
    }

    return x*pow(x,n-1);
}

const unsigned long long field_size = pow(2,s);

void build_finite_field(Long m, Long alpha_m, Long *finite_field){
    unsigned long long shift_out, keeper;
    shift_out = pow(2,m);
    keeper = shift_out-1;

    finite_field[0] = 1;
    for(unsigned long long i = 1; i < keeper ; i++){
        finite_field[i] = finite_field[i-1] << 1;
        if(finite_field[i] >= shift_out){
            finite_field[i] &= keeper;
            finite_field[i] ^= alpha_m;
        }
    }

    return;
}

int main(){
    Long finite_field[field_size];
    build_finite_field(s, 0b11111, finite_field);

    for(int i = 0; i < field_size ; i++){
        printf("%lld\t", finite_field[i]);
    }
    printf("\n");


    Long coef_f[t+1];
    Long coef_g[2] = {1,1};

    for(int i = 0; i < t ; i++){
        coef_f[i] = 0;
    }
    coef_f[t] = 1;

    Poly<Long> f (t, coef_f);
    Poly<Long> g (1, coef_g);
    Poly<Long> h = f+(g^t);
    h %= 2;

    return 0;
}
