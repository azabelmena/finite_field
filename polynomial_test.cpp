#include<stdio.h>
#include"polynomial.h"
#include"mod.h"

const Long DEFAULT_MOD = 3;

Long Mod::default_modulus = DEFAULT_MOD;

Long phi = Mod::get_totient(DEFAULT_MOD);

int main(){

    Mod coef[10] = {};

    for(int i = 0; i < 10 ; i++){
        coef[i] = Mod(i);
    }

    Poly<Mod> f(9, coef);

    printf("f(x) = ");
    for(int i = 0; i < f.deg() ; i++){
        printf("%lldx^%lld+", f[i].val(), i);
    }
    printf("%lldx^%lld\n", f[f.deg()].val(), f.deg());

    printf("deg(f) = %lld\n", f.deg());

    printf("f[%lld] = %lldx^%lld\n", 5, f[5].val(), 5);

    return 0;
}
