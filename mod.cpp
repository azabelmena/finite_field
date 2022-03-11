#include<stdio.h>
#include"mod.h"

Long DEFAULT_MOD = 4096;

Long Mod::default_modulus = DEFAULT_MOD;

Long phi = Mod::get_totient();

int main(){
    Mod a (27);
    Mod b (5);
    Mod c (7);

    Long ord_a = a.order();
    Long ord_b = b.order();
    Long ord_c = c.order();

    Mod e = a^1024;

    printf("a = %lld mod %lld\n", a.val(), a.mod());
    printf("b = %lld mod %lld\n", b.val(), b.mod());
    printf("c = %lld mod %lld\n", c.val(), c.mod());

    printf("ord(a) = %lld\n", ord_a);
    printf("e = %lld mod %lld\n", e.val(), e.mod());

    return 0;
}
