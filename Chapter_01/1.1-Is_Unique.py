#!/usr/bin/env python3

import sys


if __name__ == '__main__':
    s = ''.join(sorted(sys.argv[1]))

    for i in range(1, len(s)):
        if s[i] == s[i-1]:
            print(''.join(['String \"', sys.argv[1], '\" is NOT unique']))
            sys.exit(1)

    print(''.join(['String \"', sys.argv[1], '\" is unique']))
