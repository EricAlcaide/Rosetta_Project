#include<iostream>
#include<string>
using namespace std;

int factorialize(int n);

int main()
{
	int n;
	
	cout<<"Enter a positive integer";
	cin>>n;
	
	int res= factorialize(n);
	
	if(n>0)
	{
		cout<<"\n"<<res<<"! = "<<res;
	}
	else
	{
		cout<<"\nPlease enter a positive integer\n";
	}
	return 0;
	
}

int factorialize(int n)
{
	
	int res=1;
	int i=0;
	while(n>=1)
	{
		res*=n--;
	}
	
	return res;
}