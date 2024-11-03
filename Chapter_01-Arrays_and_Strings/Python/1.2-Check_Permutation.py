#!/usr/bin/env python3

class Solution:
    def checkPermutation(self, string1: str, string2: str) -> bool:
        if len(string1) != len(string2):
            return False

        d1 = {}
        for character in string1:
            if character not in d1:
                d1[character] = 1
            else:
                d1[character] += 1

        d2 = {}
        for character in string2:
            if character not in d2:
                d2[character] = 1
            else:
                d2[character] += 1

        for key in d1.keys():
            if key not in d2:
                return False

        return True

if __name__ == '__main__':
    solution = Solution()
    cases = [('algorithm', 'malgorith', True), ('hello', 'goodbye', False)]
    for cases in cases:
        string1 = cases[0]
        string2 = cases[1]
        expectation = cases[2]
        actual = solution.checkPermutation(string1, string2)
        assert actual == expectation
        print(string1, string2, actual, expectation)
