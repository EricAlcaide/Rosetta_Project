#include <stdio.h>
#include <cs50.h>
#include <string.h>     
#include <ctype.h> 
#include <stdlib.h>

int main(int argc, string argv[]) {
    //vars go here
    string plaintext;
    int length, k;
    
    //make sure that main has 2 arguments
    if (argc != 2) {
        printf("Does not compute. Enter a key to encypher.");
        return 1;
    }
    
    //if it does have 2 args
    printf("plaintext: ");                                      //prompt for message to encrypt
    plaintext = get_string();
    length = strlen(plaintext);                                 //get the length to iterate through later
    k = atoi(argv[1]);                                          //turn string into a number so I can work with it
    printf("ciphertext: ");                                     //wont pass check50 without this tidbit
        
    for (int i = 0; i < length; i++) {                          //iterate through string
        if isupper(plaintext[i]) {                              //if it's capital, keep it capital
            char C = ((((plaintext[i] + k) - 65) % 26) + 65);   
            printf("%c", C);
        }
        else if islower(plaintext[i]) {                         //if it's lowercase, keep it that way
            char c = ((((plaintext[i] + k) - 97) % 26) + 97);   
            printf("%c", c);
        }
        else {
            printf("%c", plaintext[i]);                         //print any other text
        }
    }
    
    printf("\n");
    return 0;
}
