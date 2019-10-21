#include<stdio.h>

int prod(int,int);

int main()
{
	int a,b;
	printf("Enter a and b: ");
	scanf("%d%d",&a,&b);
	printf("Product of %d and %d is: %d\n\n",a,b,prod(a,b));
	system("pause");
	return 0;
}

int prod(int a,int b)
{
	if (b==0)
		return 0;
	else if(b==1)
		return (a);
	else
		return (a+prod(a,b-1));
}
