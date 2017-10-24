# coding: utf8
# Factorialize code in Python for the Rosetta Stone Project
# Author: Eric Alcaide

def factorialize(num):
	return 1 if num<=1 else num*factorialize(num-1)

assert factorialize(5) == 120
assert factorialize(7) == 5040
assert factorialize(9) == 362880

print(factorialize(4))