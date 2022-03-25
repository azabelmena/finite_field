#ifndef POLYOMIAL_H
#define POLYOMIAL_H

#include<vector>

template<class K>

class Poly{
    private:
        long long degree;
        std::vector<K> coef;
    public:

/******************************************************************************
 *
 * Constructors, getters, and setters.
 *
******************************************************************************/

        // Create the 0 polynomail f(x) = 0.
        Poly<K> (){
            clear();
        }

        // Create the constant polynomail f(x) = a.
        template<class T>
        Poly<K> (T a){
            coef.clear();
            degree = 0;
            coef.resize(1);
            coef[0] = K(a);
        }

        // Create the linear polynomial $f(x) = a+bx.
        template<class T>
        Poly<K> (T a, T b){
            coef.clear();
            degree = 1;
            coef.resize(degree+1);
            coef[0] = K(a);
            coef[1] = K(b);
        }

        // Create the degree = deg polynomial a_0+a_1x+...+a_degx^deg
        // Where a_0, ..., a_deg are elements of an array.
        template<class T>
        Poly<K> (const long long deg,  const T *arr){
            if(deg < 0){
                clear();
            }

            coef.clear();
            degree = deg;
            coef.resize(degree+1);

            for(int i = 0; i < degree+1 ; i++){
                coef[i] = K(arr[i]);
            }
        }

        void clear(){
            degree = -1;
            coef.resize(1);
            coef[0] = K(0);
        }

        // Getters

        long long deg(){
            return degree;
        }

        K get(long long k) const{
            return coef[k];
        }
        K operator[](long long k) const{
            return coef[k];
        }

        K operator()(K a) const{
            if(degree <= 0){
                return K(0);
            }

            K image = K(0);

            for(int i = degree; i >= 0; i--){
                image *= a;
                image += coef[i];
            }

            return image;
        }
        Poly<K> operator()(Poly<K> f) const{}

        void minimize() const{
            coef.reserve(degree+1);
        }

        static long long max_deg(long long deg1, long long deg2){
            if(deg1 <= deg2){
                return deg2;
            }

            return deg1;
        }
        static long long max_deg(Poly<K> &f, Poly<K> &g){
            if(f.deg() <= g.deg()){
                return g.deg();
            }

            return f.deg();
        }

        int is_zero() const{
            for(int i = 0; i < degree ; i++){
                if(coef[i] != 0){
                    return false;
                }
            }

            return true;
        }

        // Setters
        void set_deg(long long a){
            degree = a;
            coef.resize(a+1);
        }

/******************************************************************************
 *
 * Arithmetic Fuctions.
 *
******************************************************************************/

        Poly<K> operator+(const Poly<K> &f) const{
           long long mdeg = max_deg(degree, f.degree);

           Poly<K> sum;
           sum.set_deg(mdeg);

           for(int i = 0; i <= mdeg ; i++){
               sum.coef[i] = get(i)+f[i];
           }

           return sum;
        }
        Poly<K> operator+(const long long a) const{
            Poly<K> sum_const = (*this);
            sum_const.coef[0] += K(a);

            return sum_const;
        }

        Poly<K> operator-(const Poly<K> &f) const{
           long long mdeg = max_deg(degree, f.degree);

           Poly<K> difference;
           difference.set_deg(mdeg);

           for(int i = 0; i <= mdeg ; i++){
               difference.coef[i] = get(i)-f[i];
           }

           return difference;
        }
        Poly<K> operator-(const long long a) const{
            Poly<K> diff_const = (*this);

            diff_const.coef[0] -= K(a);

            return diff_const;
        }
        Poly<K> operator-() const{
            Poly<K> negative;
            negative.set_deg(degree);

            for(int i = 0; i <= degree ; i++){
                negative.coef[i] = -coef[i];
            }

            return negative;
        }

        Poly<K> operator*(const Poly<K> &f) const{
            if(is_zero() || f.is_zero()){
                return Poly<K>(0);
            }

            long long sum_deg = degree+f.degree;

            Poly<K> product;

            product.set_deg(sum_deg);

            for(int k = 0; k <= sum_deg ; k++){
                for(int i = 0; i <= k ; i++){
                    if(i <= degree && k-i <= f.degree){
                        product.coef[k] += coef[i] * f.coef[k-i];
                    }
                }
            }

            return product;
        }

        Poly<K> operator%(const long long n) const{
            if(n == 0){
                return Poly<K>(0);
            }

            Poly<K> mod;
            mod.set_deg(degree);

            for(int i = 0; i <= degree ; i++){
                mod.coef[i] = get(i) % n;
            }

            return mod;
        }

        Poly<K> operator^(const long long n) const{
            if(n == 0){
                return Poly<K>(1);
            }
            else if(n == 1){
                return (*this);
            }

            Poly<K> exponent = *this;

            exponent *= exponent ^ (n-1);

            return exponent;
        }


        Poly<K> operator+=(const Poly<K> &f){
            (*this) = (*this)+f;
            return (*this);
        }
        Poly<K> operator+=(const long long a){
            (*this) = (*this)+a;
            return (*this);
        }

        Poly<K> operator-=(const Poly<K> &f){
            (*this) = (*this)-f;
            return (*this);
        }
        Poly<K> operator-=(const long long a){
            (*this) = (*this)-a;
            return (*this);
        }

        Poly<K> operator*=(const Poly<K> &f){
            (*this) = (*this) * f;

            return (*this);
        }

        Poly<K>operator%=(const long long n){
            (*this) = (*this) % n;

            return (*this);
        }

        Poly<K> operator^=(const long long n){
            (*this) = (*this) ^ n;

            return (*this);
        }
};

#endif
