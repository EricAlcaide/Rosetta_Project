# coding utf8
# Python implemtation of the Fibonacci Series with dynamic programming
# Author : Quentin Burg


def fibonacci(n):
    arr = [0,1]
    for i in range (n):
        k = arr[1] + arr[0]
        print(k, end=" ")
        arr.append(k)
        del arr[0]
    return k

fibonacci(10)
        
