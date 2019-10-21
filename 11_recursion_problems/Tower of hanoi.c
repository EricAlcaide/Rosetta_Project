#include<stdio.h>
int toh(int,char,char,char);

void main()
{
	int n;
	printf("Enter number of Discs: ");
	scanf("%d",&n);
	printf("\n\nThe sequence of steps are:\n");
	toh(n,'A','C','B');
	printf("\n\n");
	system("pause");
	
}

int toh(int n,char a,char c,char b)
{
	if(n==1)
		printf("\nMove disc %d from %c to %c.",n,a,c);
	else
	{
		toh(n-1,a,b,c);
		printf("\nMove disc %d from %c to %c.",n,a,c);
		toh(n-1,b,c,a);
	}
}
