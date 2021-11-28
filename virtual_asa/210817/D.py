import sys, math, copy
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
def input(): return sys.stdin.readline().rstrip()
from functools import reduce
def mod_comb4(n,r,mod=10**9+7):
    if r==1:return n
    elif r==0:return 1
    else:
        num=reduce(lambda x,y:x*y%mod,range(n,n-r,-1))
        den=reduce(lambda x,y:x*y%mod,range(1,r+1))
        return num*pow(den,mod-2,mod)%mod
def main():
    mod = 10**9 + 7
    inf = 10**10
    
    n, k = map(int,input().split())
    for i in range(1, k + 1):
        print(mod_comb4(k - 1, i - 1)*mod_comb4(n - k + 1, i) % mod)
    
    
if __name__=='__main__':
    main()