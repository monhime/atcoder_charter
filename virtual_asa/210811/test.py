import sys
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
def input(): return sys.stdin.readline().rstrip()
class Modint:
    mod = 0
    has_been_set = False

    def __init__(self, v=0, m=None):
        if m != None: 
            assert m >= 1
            assert not Modint.has_been_set
            Modint.mod = m
            Modint.has_been_set = True
        assert Modint.has_been_set
        self._v = v if 0 <= v < Modint.mod else v % Modint.mod


    def __add__(self, other):
        if isinstance(other, Modint):
            res = self._v + other._v
            if res > Modint.mod: res -= Modint.mod
        else:
            res = self._v + other
        return Modint(res)

    def __sub__(self, other):
        if isinstance(other, Modint):
            res = self._v - other._v
            if res < 0: res += Modint.mod
        else:
            res = self._v - other
        return Modint(res)

    def __mul__(self, other):
        if isinstance(other, Modint):
            return Modint(self._v * other._v)
        else:
            return Modint(self._v * other)

    def __floordiv__(self, other):
        if isinstance(other, Modint): other = other._v
        inv = pow(other, -1, Modint.mod)
        return Modint(self._v * inv)

    def __pow__(self, other):
        assert isinstance(other, int) and other >= 0
        return Modint(pow(self._v, other, Modint.mod))

    def __radd__(self, other):
        return Modint(self._v + other)

    def __rsub__(self, other):
        return Modint(other - self._v)  

    def __rmul__(self, other):
        return Modint(self._v * other)

    def __rfloordiv__(self, other):
        inv = pow(self._v, -1, Modint.mod)
        return Modint(other * inv)

    def __iadd__(self, other):
        if isinstance(other, Modint):
            self._v += other._v
            if self._v >= Modint.mod: self._v -= Modint.mod
        else:
            self._v += other
            if self._v < 0 or self._v >= Modint.mod: self._v %= Modint.mod
        return self

    def __isub__(self, other):
        if isinstance(other, Modint):
            self._v -= other._v
            if self._v < 0: self._v += Modint.mod
        else:
            self._v -= other
            if self._v < 0 or self._v >= Modint.mod: self._v %= Modint.mod
        return self

    def __imul__(self, other):
        if isinstance(other, Modint):
            self._v *= other._v
        else:
            self._v *= other
        if self._v < 0 or self._v >= Modint.mod: self._v %= Modint.mod
        return self

    def __ifloordiv__(self, other):
        if isinstance(other, Modint): other = other._v
        inv = pow(other, -1, Modint.mod)
        self._v *= inv       
        if self._v > Modint.mod: self._v %= Modint.mod
        return self

    def __ipow__(self, other):
        assert isinstance(other, int) and other >= 0
        self._v = pow(self._v, other, Modint.mod)
        return self

    def __eq__(self, other):
        if isinstance(other, Modint):
            return self._v == other._v
        else:
            if other < 0 or other >= Modint.mod:
                other %= Modint.mod
            return self._v == other

    def __ne__(self, other):
        if isinstance(other, Modint):
            return self._v != other._v
        else:
            if other < 0 or other >= Modint.mod:
                other %= Modint.mod
            return self._v != other

    def __str__(self):
        return str(self._v)

    def __repr__(self):
        return str(self._v)

    def __int__(self):
        return self._v
def main():
    mod = 13
    Modint(m = mod)
    a = 4
    a = Modint(a)
    print(a*4)

    
    
if __name__=='__main__':
    main()