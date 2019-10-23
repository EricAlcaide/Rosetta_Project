    //Factorial in C++ using assertion
//Author: Vidhant Matta

#include <iostream>
#include <assert.h>
using namespace std;

int factorialize(int n)
{
    unsigned long long factorial = 1;

    
    

    for(int i = 1; i <=n; ++i)
    {
        factorial *= i;
    }

    return factorial;
}

int main(){
    assert(factorialize(0) == 1);
    assert(factorialize(5) == 120);
    assert(factorialize(7) == 5040);
    assert(factorialize(9) == 362880);
}