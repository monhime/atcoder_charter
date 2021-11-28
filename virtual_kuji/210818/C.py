import sys, math, copy
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
# sys.setrecursionlimit(1000000)
def input(): return sys.stdin.readline().rstrip()
def main():
    mod = 10**9 + 7
    inf = 10**10
    
    global n
    n = int(input())
    if n == 1:
        print(1)
        sys.exit()
    if n == 2:
        print(1)
        sys.exit()

    def f(k):
        global n
        if k*(k+1)//2 <= n + 1:
            return True
        else:
            return False

    def my_bisect_right():
        left = 0
        right = n
        while right - left >1:
            mid = (left + right)//2
            if f(mid): # oooxxxx
                left = mid
            else:
                right = mid
        # return right # kを超えるの最初の要素
        return left # k以下のの最後の要素   

    print(n - my_bisect_right() + 1)

    
    
if __name__=='__main__':
    main()