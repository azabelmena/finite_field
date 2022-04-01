#include<stdio.h>
#include"polynomial.h"
#include"mod.h"

const Long DEFAULT_MOD = 3;

Long Mod::default_modulus = DEFAULT_MOD;

Long phi = Mod::get_totient(DEFAULT_MOD);

int main(){

    //Long arr[11] = {0,1,2,3,4,5,6,7,8,9,10};
    Mod arr[11] = {0,1,2,3,4,5,6,7,8,9,10};

    //Poly<Long> f (10, arr);
    //Poly<Long> g = -f;

    Poly<Mod> f (10, arr);
    Poly<Mod> g = -f;

    for(int i = 0; i <= g.deg() ; i++){
        printf("%lldx^%lld\t", g[i], i);
        //printf("%lldx^%lld\t", g[i].val(), i);
    }
    printf("\n");

    for(int i = 0; i < 10 ; i++){
        g -= i;
        for(int i = 0; i <= g.deg() ; i++){
            printf("%lldx^%lld\t", g[i], i);
            //printf("%lldx^%lld\t", g[i].val(), i);
        }
        printf("\t\t%d\n", i);
    }

    return 0;
}
