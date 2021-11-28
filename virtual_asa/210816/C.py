import sys
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
import math # math.inf
def input(): return sys.stdin.readline().rstrip()
import math
from functools import reduce
def gcd_all(numbers):#gcd(A)
    return reduce(math.gcd, numbers)
def main():
    mod = 10**9 + 7
    inf = 10**10
    
    n = int(input())
    A = list(map(int,input().split()))
    print(gcd_all(A))

    
    
if __name__=='__main__':
    main()