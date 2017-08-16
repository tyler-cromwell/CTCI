#!/usr/bin/env python3

"""
Solution to question 1.3 - URLify
Assumptions:
  - String has sufficient space to hold extra characters
  - Given true length of the string
"""

import sys


if __name__ == '__main__':
    if len(sys.argv) < 3 or not isinstance(str(sys.argv[1]), str) or not isinstance(int(sys.argv[2]), int):
        print('Please enter a string and a number on the command line')
        print('(as per assumptions afforded in the question)')
        sys.exit(1)
