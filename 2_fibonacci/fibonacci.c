/* Fibonacci implementation for Rosetta Stone project */

#include <stdio.h>

void fibonacci(void)
{
    int prev = 0;
    int cur = 1;
    int n_cur;
    
    for (int i = 0; i < 10; i++) {
        n_cur = cur + prev;
        prev = cur;
        cur = n_cur;
        
        printf("%d ", cur);
    }
    printf("\n");
}

int main(void)
{
    fibonacci();
}
