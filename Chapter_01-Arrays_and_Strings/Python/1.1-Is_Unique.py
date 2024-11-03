#!/usr/bin/env python3

class Solution:
    def __init__(self, optimize_time=True):
        self.optimizeTime = optimize_time

    def isUnique(self, string: str) -> bool:
        if self.optimizeTime:
            return self._isUniqueTime(string)
        else:
            return self._isUniqueSpace(string)

    def _isUniqueTime(self, string: str) -> bool:
        seen = set()
        for character in string:
            if character not in seen:
                seen.add(character)
            else:
                return False
        return True

    def _isUniqueSpace(self, string: list) -> bool:
        # Warning: modifies 'string' in-place
        string.sort()
        for i in range(len(string)-1):
            if string[i] == string[i+1]:
                return False
        return True

if __name__ == '__main__':
    timeSolution = Solution(optimize_time=True)
    spaceSolution = Solution(optimize_time=False)

    cases = [('algorithm', True), ('hello', False)]
    for cases in cases:
        string = cases[0]
        expectation = cases[1]
        rt = timeSolution.isUnique(string)
        rs = spaceSolution.isUnique(list(string))
        assert rt == expectation
        assert rs == expectation
        print(string, expectation, rt, rs)
