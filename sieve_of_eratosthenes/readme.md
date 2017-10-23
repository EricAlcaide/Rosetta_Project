# Sieve of Eratosthenes

The Sieve of Eratosthenes, created by Eratosthenes of Cyrene, a Greek mathematician whose sieve was survived in the works
of Nicomachus who attributed its authorship to Eratosthenes, is an algorithm for finding all prime numbers between 1 and `n`.

The complexity of this algorithm is O(n(logn)(loglogn)) with a space complexity of O(n). For example, computing all primes under 
2,000,000 requires <500ms. If a faster algorithm is desired, the Seive of Atkins would be preferable, or if a slower yet more space effecient algorithm is preferred, the Seive of Sorenson would be used.


The function takes one parameter `n` of type number which will output an array with all primes <= `n`.

For example:

sieveOfEratosthenes(100) 
sieveOfEratosthese(50)

would output these arrays respectively:

[2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]
[2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47]