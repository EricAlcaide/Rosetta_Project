#include<stdio.h>

int fact(int);

int main()
{
	int n;
	printf("Enter a number: ");
	scanf("%d",&n);
	printf("The factorial of %d is: %d\n",n,fact(n));
	system("pause");
	return 0;
}

int fact(int n)
{
	if (n==0||n==1)
		return 1;
	else
		return (n*fact(n-1));		
}
