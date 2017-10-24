#include <iostream>
using namespace std;

int main()
{
  int n=10, fib1 = 0, fib2 = 1, fibNext = 0;

  for (int i = 1; i <= n; ++i)
  {
      fibNext = fib1 + fib2;
      fib1 = fib2;
      fib2 = fibNext;

      cout <<fibNext<<endl;
  }
  return 0;
}
