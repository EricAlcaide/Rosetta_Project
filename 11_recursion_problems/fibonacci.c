#include<stdio.h>

int fab(int);

int main()
{
	int n,i;
	printf("How many terms do you want to display?: ");
	scanf("%d",&n);
	printf("The %d terms are :\n",n);
	for (i=0;i<n;i++)
		printf("%d\t",fab(i));
	printf("\n");
	system("pause");
	return 0;
}

int fab(int n)
{
	int f0,f1;
	f0=0;
	f1=1;
	if(n==0)
		return f0;
	else if (n==1)
		return f1;
	else
		return(fab(n-1)+fab(n-2));
}
