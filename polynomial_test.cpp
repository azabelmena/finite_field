#include<stdio.h>
#include"polynomial.h"
#include"mod.h"

const Long DEFAULT_MOD = 3;

Long Mod::default_modulus = DEFAULT_MOD;

Long phi = Mod::get_totient(DEFAULT_MOD);

int main(){

    Poly<Long> f(1,1);

    printf("f(x) = ");
    for(int i = 0; i < f.deg() ; i++){
        printf("%lldx^%lld+", f[i], i);
    }
    printf("%lldx^%lld\n", f[f.deg()], f.deg());


    //printf("f(x) = %lld+%lldx\n", f[0].val(), f[1].val());
    //printf("g(x) = %lld+%lldx\n", g[0].val(), g[1].val());

    //printf("h(x) = ");
    //for(int i = 0; i < h.deg() ; i++){
        //printf("%lldx^%lld+", h[i].val(), i);
    //}
    //printf("%lldx^%lld\n", h[h.deg()].val(), h.deg());

    return 0;
}
