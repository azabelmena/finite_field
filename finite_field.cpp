#include"finite_field.h"
#include"polynomial.h"
#include"mod.h"
#include<stdio.h>

int main(){

    Mod coef[] = {Mod(1), Mod(0), Mod(1)};

    Long deg = 2;

    FF a(2, coef, 2);

    Poly<Mod> m = a.prim_polynomial();

    unsigned long long characteristic = a.Char();


    return 0;
}
