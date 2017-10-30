# coding: utf8
# Python implementation of the Fibonacci Series
# Author: Eric Alcaide

def fibonacci(n):
    prev, actual = 0, 1
    if(n>0):
        print("0")
    for q in range(n):
        actual, prev = actual+prev, actual
        print(actual)

def main():
    n = input("Enter the number of terms of fibonacci numbers")
    fibonacci()

if __name__ == "__main__":
    main()
