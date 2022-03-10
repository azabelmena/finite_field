#include<stdio.h>
#include"mod.h"

Long Mod::default_modulus = default_mod;

int main(){

    Mod a(-257,8);
    Mod b(-4098, 8);

    Mod c(-6,5);
    Mod d(4,5);

    Mod e(11, 2);
    Mod f(11, 3);

    d += d;
    a -= b;
    c *= d;

    printf("%lld mod %lld\n", d);
    printf("%lld mod %lld\n", a);
    printf("%lld mod %lld\n", c);

    return 0;
}
