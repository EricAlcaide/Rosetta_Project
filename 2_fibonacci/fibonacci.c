/* Fibonacci implementation for Rosetta Stone project */

#include <stdio.h>

void fibonacci()
{
    int prev = 0;
    int cur = 1;
    int n_cur;
    int i;
    for(i = 0; i < 10; i++) {
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
