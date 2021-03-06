/*
 * Partioning.cpp
 */

#include "Partitioning.h"


int s_recursive(int n,int k)
{
    if (n==k || (n==0 && k==0))
        return 1;
    else if (k == 0){
        return 0;
    }
   return s_recursive(n-1,k-1) + k*s_recursive(n-1,k);
}

int s_dynamic(int n,int k)
{
	return 1;
}


int b_recursive(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++){
        sum += s_recursive(n,i);
    }

    return sum;
}

int b_dynamic(int n)
{
	return 0;
}


