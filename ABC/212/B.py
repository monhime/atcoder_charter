import sys
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
import math
def input(): return sys.stdin.readline().rstrip()
def f(s):
    for i, c in enumerate(s[:-1]):
        if s[i + 1] != str((int(c) + 1)%10):
            return False
    return True

def main():
    mod = 10**9 + 7
    
    s = input()
    if (s.count(s[0]) == 4) or f(s):
        print("Weak")
    else:
        print("Strong")

    
    
if __name__=='__main__':
    main()