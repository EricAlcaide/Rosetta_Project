# coding: utf8
# Python implementation of the Fibonacci Series
# Author: Eric Alcaide

def fibonacci():
    prev, actual = 0, 1

    for q in range(10):
        actual, prev = actual+prev, actual
        print(actual)

def main():
    fibonacci()

if __name__ == "__main__":
    main()
