/* Fibonacci implementation for Rosetta Stone project */

#include <iostream>
using namespace std;

void fibonacci(void)
{
    int prev = 0;
    int cur = 1;
    int n_cur;

    for (int i = 0; i < 10; i++) {
        n_cur = cur + prev;
        prev = cur;
        cur = n_cur;

        cout<<cur<<" "<<endl;
    }
}

int main(void)
{
    fibonacci();
}
