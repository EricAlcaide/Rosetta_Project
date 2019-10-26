/* Hello world implementation for Rosetta Stone. */

#include <stdio.h>

void hello(char* word)
{
    printf("Hello, World.\n");
    printf("%s\n", word);
}

void main(void)
{
 
    char* word = "Hello, World.";
    hello(word);
    
}
