#include<stdio.h>
#include<string.h>

void main(){
	int n,m,i,j;
	char text[100],pattern[100];
	printf("Enter the text string: ");
	gets(text);
	printf("Enter the pattern string: ");
	gets(pattern);
	n = strlen(text);
	m = strlen(pattern);

	for(i = 0; i < n; i++){
		text[i] = tolower(text[i]);
	}

	for(i = 0; i < m; i++){
		pattern[i] = tolower(pattern[i]);
	}

	for(i=0; i < n-m; i++){
		if(text[i] == pattern[0]){
			for(j=0; j < m; j++){
				if(pattern[j] != text[j+i])
					break;
			}
			if(j == m)
				printf("Pattern found at position %d.\n", i + 1);
		}
	}
	// getch();
}
