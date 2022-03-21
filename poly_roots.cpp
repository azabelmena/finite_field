#include<stdio.h>
#include"polynomial.h"
#include"mod.h"

// Declare the characteristic of the field.
const Long DEFAULT_MOD = 2;
Long Mod::default_modulus = DEFAULT_MOD;

// Values for t and s/
const Long t = 5;
const Long s = 5;

int main(){

    Long coef[t+1] = {};

    Long c = 1;

    for(int i = 0; i < t; i++){
        coef[i] = 0;
    }
    coef[t] = 1;

    Poly<Mod> f (t, coef);
    Poly<Mod> g (Mod(1), Mod(1));
    Poly<Mod> h = g ^ t;
    Poly<Mod> k = f+h;

    printf("x^%lld = \t", t);
    for(int i = 0; i <= f.deg() ; i++){
        printf("%lldx^%lld\t", f[i].val(), i);
    }
    printf("\n");

    printf("1+x = \t");
    for(int i = 0; i <= g.deg() ; i++){
        printf("%lldx^%lld\t", h[i].val(), i);
    }
    printf("\n");

    printf("(1+x)^%lld = \t", t);
    for(int i = 0; i <= h.deg() ; i++){
        printf("%lldx^%lld\t", h[i].val(), i);
    }
    printf("\n");

    printf("x^%lld+(1+x)^%lld = \t", t, t);
    for(int i = 0; i <= k.deg() ; i++){
        printf("%lldx^%lld\t", k[i].val(), i);
    }
    printf("\n");

    return 0;
}
