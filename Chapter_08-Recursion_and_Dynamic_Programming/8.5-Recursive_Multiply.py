#!/usr/bin/env python3

##################################################
#  Solution to question 8.5 - Recursive Multiply
# 
#  Status: COMPLETE
#
#  TODO:
#    - Prevent maxing out recursion depth (996)
##################################################

import getopt
import sys


# Core multiply function
def _multiply(a, b):
    if b == 0:
        return 0
    else:
        return a + _multiply(a, b-1)


# Preliminary multiply function
def multiply(a, b):
    if a < b:
        # Use smaller number for recursion depth
        return _multiply(b, a)
    else:
        return _multiply(a, b)


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
