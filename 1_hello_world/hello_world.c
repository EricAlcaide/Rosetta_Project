/* Hello world implementation for Rosetta Stone. */

#include <stdio.h>

void hello(char* word)
{
    printf("Hello, World.\n"); // prints hello world
    printf("%s\n", word);
}

int main(void)
{
    char* word = "Hello, World.";
    hello(word);
    return 0;
}
