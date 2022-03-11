#include<stdio.h>
#include"mod.h"

const Long DEFAULT_MOD = 256;

Long Mod::default_modulus = DEFAULT_MOD;

Long phi = Mod::get_totient(DEFAULT_MOD);

void totient_test(){
    Long phi_m = 0, phi_n = 0, phi_mn = 0;

    for(int m = 1; m < 257 ; m++){
        for(int n = 1; n < 257 ; n++){
            phi_m = Mod::get_totient(m);
            phi_n = Mod::get_totient(n);
            phi_mn = Mod::get_totient(n * m);

            printf("phi(%lld) = %lld\t", m, phi_m);
            printf("phi(%lld) = %lld\t", n, phi_n);
            printf("phi(%lld) = %lld\t | ", m*n, phi_mn);
            printf("\t");

            printf("phi(%lld) = phi(%lld)phi(%lld):\t%d\n", m*n, m,
                    n, phi_mn == phi_m*phi_n);
        }
    }
}

// use only with primes.
void prim_root_test(Long mod){
    int veracity = false;
    for(int a = 0; a <= mod ; a++){
        Mod prim_root (a,mod);
        Long pow = prim_root.order();

        if(pow == mod-1){
            veracity = true;
        }

        printf("%lld^%lld = 1 mod %lld\t | ", prim_root.val(), pow, mod);
        printf("\t");
        printf("%d\n", veracity);
    }
}

int main(){

    printf("Totient test.");
    //printf("-------------------------------------------------------------------\n");
    totient_test();
    //printf("-------------------------------------------------------------------\n");

     //prim_root test.
    //printf("Primitive root test.\n");
    //printf("----------------- p = 2 -------------------------------------------\n");
    //prim_root_test(2);
    //printf("----------------- p = 3 -------------------------------------------\n");
    //prim_root_test(3);
    //printf("----------------- p = 5 -------------------------------------------\n");
    //prim_root_test(5);
    //printf("----------------- p = 7 -------------------------------------------\n");
    //prim_root_test(7);
    //printf("----------------- p = 11 -------------------------------------------\n");
    //prim_root_test(11);
    //printf("----------------- p = 13 -------------------------------------------\n");
    //prim_root_test(13);
    //printf("----------------- p = 17 -------------------------------------------\n");
    //prim_root_test(17);
    //printf("-------------------------------------------------------------------\n");

    return 0;
}
