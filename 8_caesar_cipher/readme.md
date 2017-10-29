# Caesar Cipher

### The Problem

The Caesar cipher is an encryption technique in which each letter in the original text is replaced by a letter some position up or down the alphabet.
More info on the algorithm: https://learncryptography.com/classical-encryption/caesar-cipher

### Desired output / Test cases

* **Input** Text to be encrypted, shift
* **Output** Encrypted text

### Examples
caesar('abcde', shift=3) == 'defgh'
caesar('A not so long string', shift: 2) == 'C pqv uq nqpi uvtkpi'
caesar('Negative shift', shift: -1) == 'Mdfzshud rghes'
