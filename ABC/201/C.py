import sys, math, copy
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
def input(): return sys.stdin.readline().rstrip()
def main():
    mod = 10**9 + 7
    inf = 10**10
    
    s = input() 
    s_lis = list(product(list(range(10)), repeat = 4))
    ans = 0
    for _s in s_lis:
        o_flag = [False]*10
        for c in _s:
            if s[c] == 'o':
                o_flag[c] = True
            if s[c] == "x":
                break
        else:
            for i in range(10):
                if s[i] == 'o' and not o_flag[i]:
                    break
            else:
                ans += 1
    print(ans)
     
    
if __name__=='__main__':
    main()