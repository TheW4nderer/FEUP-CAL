/*
 * Factorial.cpp
 */

#include "Factorial.h"

int factorialRecurs(int n)
{
    if (n==0) return 1;
	return factorialRecurs(n-1) * n;

}

int factorialDinam(int n)
{
    int result = n;
    for (int i = 1; i < n; i++){
        result *= i;
    }
	return result;
}
