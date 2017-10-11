#!/usr/bin/env python3

##################################################
#  Solution to question 8.9 - Parens
# 
#  Status: INCOMPLETE
##################################################

import getopt
import sys

import structs


def _parens(stack, n):
    if n == 0:
        return ''
    else:
        stack.push(')')
        s = '('+ _parens(stack, n-1)
        return s + stack.pop()


def parens(n):
    stack = structs.Stack(')')
    return '('+ _parens(stack, n-1) + stack.pop()


# Main body
if __name__ == '__main__':
    try:
        short_opts = 'm:n:'
        long_opts = ['help', 'n=']
        opts, args = getopt.getopt(sys.argv[1:], short_opts, long_opts)
    except getopt.GetoptError as error:
        print('Invalid argument: \"{}\"\n'.format(str(error)))
        print('Please enter [-n | --n=] when executing')

    if len(opts) == 0:
        print('Please enter [-n | --n=] when executing')

    n = 0

    for o, a, in opts:
        if o == '-n' or o == '--n':
            n = int(a)

    if n < 1:
        print('N must be greater than 0')
    else:
        print(n, '->', parens(n))
