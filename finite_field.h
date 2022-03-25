#ifndef FINITE_FIELD_H
#define FINITE_FIELD_H

#include<vector>
#include"polynomial.h"
#include"mod.h"

const Long DEFAULT_MOD = 2;

Long Mod::default_modulus = DEFAULT_MOD;

class FF{
    private:
        Poly<Mod> prim_poly;
        unsigned long long characteristic;
    public:
        FF(){
            characteristic = 2;
            Mod coefficient[] = {Mod(1, characteristic)};
            prim_poly = Poly<Mod> (0, coefficient);
        }
        FF(unsigned long long _char){
            characteristic = _char;
            Mod coefficient[] = {Mod(1, characteristic)};
            prim_poly = Poly<Mod> (0, coefficient);
        }
        FF(unsigned long long _char, Mod *coef, long long deg){
            characteristic = _char;
            Mod *coefficient = coef;
            prim_poly = Poly<Mod> (deg, coefficient);
        }

        Poly<Mod> prim_polynomial(){
            return prim_poly;
        }

        unsigned long long Char(){
            return characteristic;
        }
};

#endif
