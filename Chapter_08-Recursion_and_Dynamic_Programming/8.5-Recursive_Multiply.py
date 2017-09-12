#!/usr/bin/env python3

##################################################
#  Solution to question 8.5 - Recursive Multiply
# 
#  Status: COMPLETE
##################################################

import getopt
import sys


# Core multiply function
def _multiply(m, n, a):
    if n == 1:
        return m + a    # Sum argument 1 and accumulator

    # Odd
    elif n % 2 == 1:
        a += m  # Increase accumulator
        n -= 1  # Decrement argument 2

    m = m << 1  # Multiply by 2
    n = n >> 1  # Divide by 2
    return _multiply(m, n, a)


# Preliminary multiply function
def multiply(m, n):
    if m < n:
        # Use smaller number for recursion depth
        return _multiply(n, m, 0)
    else:
        return _multiply(m, n, 0)


# Main body
if __name__ == '__main__':
    try:
        short_opts = 'm:n:'
        long_opts = ['help', 'm=', 'n=']
        opts, args = getopt.getopt(sys.argv[1:], short_opts, long_opts)
    except getopt.GetoptError as error:
        print('Invalid argument: \"{}\"\n'.format(str(error)))
        print('Please enter m=(somthing) and n=(something) when executing')

    if len(opts) == 0:
        print('Please enter m=(somthing) and n=(something) when executing')

    m = 0
    n = 0

    for o, a, in opts:
        if o == '-m' or o == '--m':
            m = int(a)
        elif o == '-n' or o == '--n':
            n = int(a)

    print('{} * {} ='.format(m, n), multiply(m, n))
