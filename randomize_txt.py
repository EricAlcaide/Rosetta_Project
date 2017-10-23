# Reading is cool.
# Here is how to open, randomize, and print out random lines from your favorite book.
# Built as a tiny part of my Twitter bot. Thanks to the many good souls on SO for contributing.

import random

# Open text file and randomize lines
with open('myfavbook.txt', 'r') as book:
    book_lines = book.read().split('.')
random.shuffle(book_lines)

# Get random line
def tweeter():
    for line in book_lines:
        print line
