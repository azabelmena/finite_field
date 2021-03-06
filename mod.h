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

        static const Long gcd(Long a, Long b){
            Long d;
            if(b == 0){
                if(a<0){
                    d = -a;
                }
                else{
                    d = a;
                }

                return d;
            }
            if(b<0){
                d = gcd(a,-b);

                return d;
            }
            if(a<0){
                d = gcd(-a,b);

                return d;
            }

            Long aa = b;
            Long bb = a%b;
            Long qq = a/b;

            d = gcd(aa,bb);

            return d;
        }

        static const Long gcd(Long a, Long b, Long &x, Long &y){
            Long d;
            if(b == 0){
                if(a<0){
                    d = -a;
                    x = -1;
                    y = 0;
                }
                else{
                    d = a;
                    x = 1;
                    y = 0;
                }

                return d;
            }
            if(b<0){
                d = gcd(a,-b,x,y);
                y = -y;

                return d;
            }
            if(a<0){
                d = gcd(-a,b,x,y);
                x = -x;

                return d;
            }

            Long aa = b;
            Long bb = a%b;
            Long qq = a/b;
            Long xx,yy;

            d = gcd(aa,bb,xx,yy);

            x = yy;
            y = xx-qq*yy;

            return d;
        }

        static const Long totient(Long mod){
            Long totient = 0;

            for(int n = 0; n < mod ; n++){
                if(gcd(n,mod) == 1){
                    totient++;
                }
            }

            return totient;
        }

    public:

/******************************************************************************
 *
 * Constructors, getters, and setters.
 *
******************************************************************************/

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

        static Long get_gcd(Long a, Long b){
            return gcd(a,b);
        }
        static Long get_gcd(Long a, Long b, Long &x, Long &y){
            return gcd(a,b,x,y);
        }

        static Long get_totient(Long mod){
            return totient(mod);
        }

        // setters
        void set_mod(Long mod){
            if(mod <= 0){
                modulus = 0;
                value = 0;
            }
            else{
                modulus = mod;
                value %= mod;
                if(value < 0){
                    value += mod;
                }
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

/******************************************************************************
 *
 * Arithmetic Fuctions.
 *
******************************************************************************/

        Long pow(Long val, Long x) const{
            if(x == 1){
                return val;
            }

            return val*pow(val,x-1);
        }

        Mod inverse() const{
            if(!modulus){
                return Mod(0,0);
            }
            Long d, a, b;
            Long mod = modulus, val = value;

            d = gcd(val, mod, a, b);

            if(d > 1){
                return Mod(0,0);
            }

            return Mod(a, modulus);
        }

        Mod add(Mod mod) const{
            if(!modulus || !mod.modulus){
                return Mod(0,0);
            }
            if(modulus != mod.modulus){
                return Mod(0,0);
            }

            return Mod(value+mod.value, modulus);
        }

        Mod sub(Mod mod) const{
            if(!modulus || !mod.modulus){
                return Mod(0,0);
            }
            if(modulus != mod.modulus){
                return Mod(0,0);
            }

            return Mod(value-mod.value, modulus);
        }

        Mod mul(Mod mod) const {
            if(!modulus || !mod.modulus){
                return Mod(0,0);
            }
            if(modulus != mod.modulus){
                return Mod(0,0);
            }

            return Mod(value*mod.value, modulus);
        }

        Mod pow(Long x) const {
            if(!modulus){
                return Mod(0,0);
            }

            if(x == 0){
                return Mod(1,modulus);
            }

            if(x < 0){
                return (Mod(pow(value, -x), modulus).inverse());
            }

            return Mod(pow(value, x), modulus);
        }

        Long order() const{
            if(value == 1){
                return 1;
            }
            Long ord = 0;
            for(Long k = 1; k <= totient(modulus) ; k++){
                if(pow(k) == 1){
                    ord = k;
                }
            }

            return ord;
        }
        Long order(Long mod) const{
            if(value == 1){
                return 1;
            }
            Long ord = 0;
            Mod m (value, mod);
            for(Long k = 1; k <= totient(mod) ; k++){
                if(m.pow(k) == 1){
                    ord = k;
                }
            }

            return ord;
        }


/******************************************************************************
 *
 * Operators
 *
******************************************************************************/

        // Arithmetic Operators 1.
        Mod operator+(const Mod &mod) const {
            return add(mod);
        }
        Mod operator+(Long x) const {
            return add(Mod(x,modulus));
        }

        Mod operator-() const {
            return Mod(-value, modulus);
        }
        Mod operator-(const Mod &mod) const {
            return sub(mod);
        }
        Mod operator-(Long x) const {
            return sub(Mod(x,modulus));
        }

        Mod operator*(const Mod &mod) const {
            return mul(mod);
        }
        Mod operator*(Long x) const {
            return mul(Mod(x,modulus));
        }

        Mod operator^(Long x) const {
            return pow(x);
        }

        Mod operator/(const Mod &mod) const{
            return mul(mod.inverse());
        }
        Mod operator/(Long x) const {
            return mul(Mod(x,modulus).inverse());
        }

        // Arithmetic Operators 2.

        Mod operator+=(const Mod &mod){
            return (*this = add(mod));
        }
        Mod operator+=(Long x){
            return (*this = add(Mod(x,modulus)));
        }

        Mod operator-=(const Mod &mod){
            return (*this = sub(mod));
        }
        Mod operator-=(Long x){
            return (*this = sub(Mod(x,modulus)));
        }

        Mod operator*=(const Mod &mod){
            return (*this = mul(mod));
        }
        Mod operator*=(Long x){
            return (*this = mul(Mod(x,modulus)));
        }

        Mod operator^=(Long x){
            return (*this = pow(x));
        }

        Mod operator/=(const Mod &mod){
            return (*this = mul(mod.inverse()));
        }
        Mod operator/=(Long x){
            return (*this = mul(Mod(x,modulus).inverse()));
        }

        // Comparison operators.

        int operator==(const Mod &mod) const{
            return ((value == mod.value) && (modulus == mod.modulus));
        }
        int operator==(Long x) const{
            return ((value == Mod(x,modulus).value));
        }

        int operator!=(const Mod &mod) const{
            return ((value != mod.value) || (modulus != mod.modulus));
        }
        int operator!=(Long x) const{
            return ((value != Mod(x,modulus).value));
        }

        int operator<(const Mod &mod) const{
            if(modulus < mod.modulus){
                return true;
            }

            return (value < mod.value);
        }
        int operator<(Long x) const{
            return (value < Mod(x,modulus).value);
        }

        int operator>(const Mod &mod) const{
            if(modulus > mod.modulus){
                return (value > mod.value);
            }

            return false;
        }
        int operator>(Long x) const{
            return (value > Mod(x,modulus).value);
        }

        int operator>=(const Mod &mod) const{
            if(modulus >= mod.modulus){
                return (value >= mod.value);
            }

            return false;
        }
        int operator>=(Long x) const{
            return (value >= Mod(x,modulus).value);
        }

        int operator<=(const Mod &mod) const{
            if(modulus <= mod.modulus){
                return true;
            }

            return (value <= mod.value);
        }
        int operator<=(Long x) const{
            return (value <= Mod(x,modulus).value);
        }

};

#endif
