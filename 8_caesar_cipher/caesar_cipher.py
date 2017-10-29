import string
from functools import reduce


def caesar(plain, shift):
    def substitute(acc, letter):
        if not letter.isalpha():
            return acc + letter

        idx = alphabet.find(letter)
        letters = alphabet[:26] if idx < 26 else alphabet[26:]
        return acc + letters[(idx + shift) % 26]

    alphabet = string.ascii_letters

    result = reduce(
        substitute,
        plain,
        ''
    )

    return result


def main():
    assert caesar('AzaZ', shift=1) == 'BabA'
    assert caesar('AzaZ', shift=-1) == 'ZyzY'
    assert caesar('This is a caesar cipher example', shift=0) == 'This is a caesar cipher example'
    assert caesar('A not so long string', shift=2) == 'C pqv uq nqpi uvtkpi'
    assert caesar('Negative shift', shift=-1) == 'Mdfzshud rghes'


if __name__ == '__main__':
    main()
