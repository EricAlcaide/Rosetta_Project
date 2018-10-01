#include <iostream>
#include <assert.h>

using namespace std;

int main()
{
	cout << "Please enter a number: ";
	unsigned long n;
	cin >> n;
	if (n < 0)
		assert("Factorial cannot be negative.");
	unsigned long output(1);
	if (n != 0)
	{
		for (unsigned long i(1); i < n + 1; ++i)
		{
			output *= i;
		}
	}
	cout << output;
	return 0;
}