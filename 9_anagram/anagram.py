# coding: utf8


def is_anagram(string1, string2):
    string1 = ''.join(string1.split(' ')).lower()
    string2 = ''.join(string2.split(' ')).lower()

    if len(string1) != len(string2):
        return False

    letters = {}
    for letter in string1:
        if letter in letters:
            letters[letter] += 1
        else:
            letters[letter] = 1

    for letter in string2:
        if letter in letters:
            letters[letter] -= 1
        else:
            return False

    for letter in letters:
        if letters[letter] != 0:
            return False

    return True


def main():
    anagrams = [
        ("rail safety", "fairy tales"),
        ("some rail safety", "fairy tales"),
        ("Clint Eastwood", "Old West action"),
        ("Clint Eastwood", "Old East action"),
        ("funeral", "real fun")]

    for anagram in anagrams:
        if is_anagram(anagram[0], anagram[1]):
            print("{1} the anagram from {0}".format(anagram[0], anagram[1]))
        else:
            print("{1} not the anagram from {0}".format(anagram[0], anagram[1]))


if __name__ == "__main__":
    main()
