#!/usr/bin/env python3

class Solution:
    def palindrome_permutation(self, string: str) -> bool:
        d = {}
        for i in range(len(string)):
            c = string[i].lower()
            if c.isspace():
                continue
            elif c not in d:
                d[c] = 1
            else:
                d[c] += 1

        odds = 0
        evens = 0
        for k in d:
            if d[k] % 2 == 1:
                odds += 1
            else:
                evens += 1

        if odds <= 1:
            return True
        else:
            return False

solution = Solution()
string = 'Tact Coa'
output = solution.palindrome_permutation(string)
print(output)
