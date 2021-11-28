import sys
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
import math
def input(): return sys.stdin.readline().rstrip()
def main():
    mod = 10**9 + 7
    
    n = int(input())
    A = list(map(int,input().split()))
    mod_A = [a % 200 for a in A]
    mod_A_c = Counter(mod_A)
    ans = 0
    for m_A_c in mod_A_c.values():
        ans += m_A_c*(m_A_c - 1)//2
    print(ans)

    
    
if __name__=='__main__':
    main()