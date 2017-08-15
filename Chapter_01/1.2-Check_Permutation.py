#!/usr/bin/env python3

"""
Solution to question 1.2 - Check Permutation
Assumptions:
  - Case sensitive
"""

import sys


if __name__ == '__main__':
    if len(sys.argv) < 3:
        print('Please enter two strings on the command line')
        sys.exit(1)
    else:
        print(''.join(['String \"', sys.argv[2], '\" is permutation a of \"', sys.argv[1], '\": ']), end='')

    s1 = ''.join(sorted(sys.argv[1]))
    s2 = ''.join(sorted(sys.argv[2]))

    if s1 != s2:
        print('false')
        sys.exit(1)
    else:
        print('true')
