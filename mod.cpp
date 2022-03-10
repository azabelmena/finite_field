#include<stdio.h>
#include"mod.h"

Long Mod::default_modulus = 8;

int main(){

    Mod a(257);

    printf("a = %lld mod %lld\n", a.val(), a.mod());

    return 0;
}
