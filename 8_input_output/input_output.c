#include <stdio.h>

void main(){

    // Only reads up to 100 chars
    char str[100];

    printf("Enter a value: ");
    scanf("%s", str);

    printf("You entered: \"%s\"\n", str);

}
