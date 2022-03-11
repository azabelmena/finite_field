#include<stdio.h>
#include"mod.h"

Long Mod::default_modulus = 8;

int main(){
    Mod a (7);
    Mod b (5);
    Mod c (6);

    a ^= 2;
    b ^= 2;
    c ^= 2;

    printf("a = %lld mod %lld \n", a, a.mod());
    printf("b = %lld mod %lld \n", b, b.mod());
    printf("c = %lld mod %lld \n", c, c.mod());

    return 0;
}
