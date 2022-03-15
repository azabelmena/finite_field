#ifndef POLYOMIAL_H
#define POLYOMIAL_H

#include<vector>

template<class K, T, A, B, C>

class Poly{
    private:
        long long deg;
        std::vector<K> coef;
    public:

        //Constructors and initializers.
        Poly<K> (){
            clear();
        }
        Poly<K> (T a){
            coef.clear();
            deg = 0;
            coef.resize(1);
            coef[0] = {K(a)};
        }
        Poly<K> (const long long arr_size,  const T *arr){
            if(arr_size < 0){
                clear();
            }

            coef.clear();
            deg = arr_size;
            coef.resize(deg+1);

            for(int i = 0; i < deg ; i++){
                coef[i] = K(arr[i]);
            }
        }

        void clear(){
            deg = -1;
            coef.resize(1);
            coef[0] = {K(0)};
        }

        // Getters

        long long deg(){
            return deg;
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
