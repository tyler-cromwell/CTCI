#!/usr/bin/env python3

import sys


if __name__ == '__main__':
    if len(sys.argv) < 2:
        print('Please enter a string on the command line')
        sys.exit(1)
    else:
        print(''.join(['String \"', sys.argv[1], '\" is unique: ']), end='')

    s = ''.join(sorted(sys.argv[1]))

    for i in range(1, len(s)):
        if s[i] == s[i-1]:
            print('false')
            sys.exit(1)

    print('true')
