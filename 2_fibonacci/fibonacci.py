# coding: utf8
# Python implementation of the Fibonacci Series
# Author: Eric Alcaide

def fibonacci(a):
    prev, actual = 0, 1
    
    for q in range(a):
        actual, prev = actual+prev, actual
        print(actual)

def main():
	print("Enter the number upto which to take fibonacci:",end=" ")
	a=int(input())
	fibonacci(a)

if __name__ == "__main__":
    main()
