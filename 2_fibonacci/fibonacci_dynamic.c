#include <stdio.h>
#include <stdlib.h>


void fibonacci(int n) {
  int arr[2], k, temp;
  arr[0] = 0;
  arr[1] = 1;
  for (int i = 0 ; i < n ; i++) {
    k = arr[0] + arr[1];
    temp = arr[1];
    arr[0] = temp;
    arr[1] = k;
    printf('%d', k);
  }
  return;
}

int main() {
  fibonacci(10);
  return 0;  
}
