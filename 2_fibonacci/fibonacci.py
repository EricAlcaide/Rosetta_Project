# coding: utf8
# Python implementation of the Fibonacci Series
# Author: Eric Alcaide

def fibonacci():
    prev, actual = 0, 1
    n=int(input("Enter the no. of terms you want in fibbonacci series:"))
    
    for q in range(n):
        actual, prev = actual+prev, actual
        print(actual)

def main():
    fibonacci()

if __name__ == "__main__":
    main()
