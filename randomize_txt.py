# Reading is cool.
# Here is how to open, randomize, and print out random lines from your favorite book.
# Tiny part of my Twitter bot w/o SO's help.

import random

# Open text file and randomize lines
with open('myfavbook.txt', 'r') as book:
    book_lines = book.read().split('.')
random.shuffle(book_lines)

# Get random line
def tweeter():
    for line in book_lines:
        print line
