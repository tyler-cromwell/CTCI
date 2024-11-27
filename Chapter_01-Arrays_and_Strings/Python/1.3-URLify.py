#!/usr/bin/env python3

class Solution:
    def URLify(self, string: list, length: int) -> str:
        n = len(string)
        ptrSpace = n-1
        ptrChar = length-1

        spaces = 0
        for i in range(length):
            if string[i].isspace():
                spaces += 1

        while ptrChar >= 0 and spaces > 0:
            if not string[ptrChar].isspace():
                string[ptrSpace] = string[ptrChar]
                string[ptrChar] = ' '
                ptrSpace -= 1
            else:
                string[ptrSpace] = '0'
                ptrSpace -= 1
                string[ptrSpace] = '2'
                ptrSpace -= 1
                string[ptrSpace] = '%'
                ptrSpace -= 1
                spaces -= 1
            ptrChar -= 1
        return ''.join(string)

solution = Solution()
string = "Mr John Smith    "
length = 13
output = solution.URLify(list(string), length)
print(output)
