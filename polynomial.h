#ifndef POLYOMIAL_H
#define POLYOMIAL_H

#include<vector>

template<class K>

class Poly{
    private:
        long long degree;
        std::vector<K> coef;
    public:

        //Constructors and initializers.
        Poly<K> (){
            clear();
        }

        template<class T>
        Poly<K> (T a){
            coef.clear();
            degree = 0;
            coef.resize(1);
            coef[0] = {K(a)};
        }

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
            coef[0] = {K(0)};
        }

        // Getters

        long long deg(){
            return degree;
        }

        K get(long long k){
            return coef[k];
        }
        K operator[](long long k){
            return coef[k];
        }

        // Setters.
};

#endif
