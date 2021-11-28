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
    s = input()
    ans = 0

    left = -1
    right = n
    while True:
        left += 1
        if s[left] == "W":  
            while True:
                right -= 1
                if s[right] == "R": # 交換する
                    ans += 1
                    break
                if right == left + 1:
                    print(ans)
                    sys.exit()
        if  right == left + 1:
            print(ans)
            sys.exit()
            
if __name__=='__main__':
    main()