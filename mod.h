#ifndef MOD_H
#define MOD_H

typedef long long Long;

// The default modulus to be used, if not specified, will be mod 2.
const Long default_mod = 2;

class Mod{
    private:
        Long value;
        Long modulus;
        static Long default_modulus;

    public:
        // Constructors.
        Mod(){ // Defualt constructor, specifies just the default modulus.
            modulus = get_default_mod();
            value = 0;
        }
        // Specify a Mod object with a given modulus.
        Mod(Long val){
            modulus = get_default_mod();

            value = val % modulus;
            if(value < 0){
                value += modulus;
            }
        }
        // Specify a Mod object with given modulus, and value reduced by that
        // modulus.
        Mod(Long val, Long mod){
            if(mod <= 0){
                modulus = 0;
                value = 0;
            }
            else{
                modulus = mod;
                value = val % modulus;
                if(value < 0){
                    value += modulus;
                }
            }
        }

        //getters
        const Long mod() const{
            return modulus;
        }

        const Long val() const{
            return value;
        }

        static Long get_default_mod(){
            return default_modulus;
        }

        // setters
        void set_mod(Long mod){
            if(mod <= 0){
                modulus = 0;
                value = 0;
            }
            else{
                modulus = mod;
            }
        }

        void set_val(Long val){
            value = val % modulus;
            if(value < 0){
                value += modulus;
            }
        }

        static void set_default_mod(Long mod){
            if(mod <= 0){
                default_modulus = default_mod;
            }
            else{
                default_modulus = mod;
            }
        }

        // Arithmetic
        Mod add(const Mod mod){
            if(!modulus || !mod.modulus){
                return Mod(0,0);
            }
            if(modulus != mod.modulus){
                return Mod(0,0);
            }

            return Mod(value+mod.value, modulus);
        }

        Mod sub(const Mod mod){
            if(!modulus || !mod.modulus){
                return Mod(0,0);
            }
            if(modulus != mod.modulus){
                return Mod(0,0);
            }

            return Mod(value-mod.value, modulus);
        }

        Mod mul(const Mod mod){
            if(!modulus || !mod.modulus){
                return Mod(0,0);
            }
            if(modulus != mod.modulus){
                return Mod(0,0);
            }

            return Mod(value*mod.value, modulus);
        }


        // Operators.
        int operator==(const Mod &mod) const{
            return ((value == mod.value) && (modulus == mod.modulus));
        }
        int operator!=(const Mod &mod) const{
            return ((value != mod.value) || (modulus != mod.modulus));
        }
        int operator<(const Mod &mod) const{
            return (value < mod.value) && (modulus < mod.modulus);
        }
        int operator>(const Mod &mod) const{
            return (value > mod.value) && (modulus > mod.modulus);
        }
        int operator>=(const Mod &mod) const{
            return (value >= mod.value) && (modulus >= mod.modulus);
        }
        int operator<=(const Mod &mod) const{
            return (value <= mod.value) && (modulus <= mod.modulus);
        }

        Mod operator+=(const Mod &mod){
            *this = add(mod);
            return *this;
        }
        Mod operator-=(const Mod &mod){
            *this = sub(mod);
            return *this;
        }
        Mod operator*=(const Mod &mod){
            *this = mul(mod);
            return *this;
        }

};

#endif
