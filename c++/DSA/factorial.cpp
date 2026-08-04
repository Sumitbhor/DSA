#include<iostream>
using namespace std ;

int factorialN(int N)
{
    if (N < 0)
        return -1;

    int fact = 1;

    for (int i = 1; i <= N; i++)
        fact *= i;

    return fact;
}

int main()
{
   int  fact = factorialN(10);
   cout << fact;
    return 0;
}

