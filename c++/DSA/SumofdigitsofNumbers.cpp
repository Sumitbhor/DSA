#include <iostream>
using namespace std;
int CalculteSumOfDigitsofNUmber(int num1)
{
    int sum = 0;
    while (num1 > 0)
    {
        int num = num1 % 10;
        sum += num;
        num1 = num1 / 10;
    }
    return sum ;
}

int main()
{
    int sumofDigit= CalculteSumOfDigitsofNUmber(45254); 
    cout<<sumofDigit <<endl ;
    return 0;
}
