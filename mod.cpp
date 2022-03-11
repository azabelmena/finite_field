#include<stdio.h>
#include"mod.h"

Long DEFAULT_MOD = 256;
Long MOD_8 = 8;

Long Mod::default_modulus = DEFAULT_MOD;

Long phi_256 = Mod::get_totient(DEFAULT_MOD);
Long phi_8 = Mod::get_totient(MOD_8);

int main(){

    printf("phi(%lld) = %lld\n", DEFAULT_MOD, phi_256);
    printf("phi(%lld) = %lld\n", MOD_8, phi_8);
    printf("phi(%lld * %lld) = %lld\n", DEFAULT_MOD,MOD_8, phi_256*phi_8);

    Mod a (27, 64);
    Mod b (2, 3);
    Mod c (61, 9);
    Mod e (1, 2);


    printf("a = %lld mod %lld\n", a.val(), a.mod());
    printf("a = %lld mod %lld\n", b.val(), b.mod());
    printf("a = %lld mod %lld\n", c.val(), c.mod());
    printf("a = %lld mod %lld\n", e.val(), e.mod());

    printf("ord(a) = %lld\n", a.order());
    printf("ord(b) = %lld\n", b.order());
    printf("ord(c) = %lld\n", c.order());
    printf("ord(e) = %lld\n", e.order());

    printf("ord_73(a) = %lld\n", a.order(73));
    printf("ord_73(b) = %lld\n", b.order(73));
    printf("ord_73(c) = %lld\n", c.order(73));
    printf("ord_73(e) = %lld\n", e.order(73));


    return 0;
}
