/*
 * Sum.cpp
 */

#include "Sum.h"
#include <chrono>
#include <vector>

string calcSum(int* sequence, int size)
{
    auto start = std::chrono::high_resolution_clock::now();
    string out = "";

    int sum[size];
    int min, idx;

    for(int m=1; m <= size; m++){   //Tamanho da sequência
        min = INT_MAX;
        for(int i=0; i <= size-m ; i++){    //Percorrer a sequência com tamanho m
            if(m==1){
                sum[i]= sequence[i];
            }
            else{
                sum[i]=sum[i]+sequence[i+m-1];  //Usar o vetor sum dinâmicamente, porque é a soma dos valores anteriores da
                                                // iteração anterior, a este valor basta somar a próximo valor da sequência, de indice i+m-1
            }
            if(sum[i]<min){
                min=sum[i];
                idx=i;
            }
        }
        out += to_string(sum[idx])+ ","+ to_string(idx)+";";
    }
    auto finish = std::chrono::high_resolution_clock::now();
    auto mili = chrono::duration_cast<chrono::milliseconds>(finish-start).count();

    return out;
}

