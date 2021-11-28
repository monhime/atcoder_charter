from os import initgroups
import sys
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
def input(): return sys.stdin.readline().rstrip()
def main():
    mod = 10**9 + 7
    
    s = input()
    for zero_num in range(10):
        s_new = "0"*zero_num + s
        for c_1, c_2 in zip(s_new, reversed(s_new)):
            if c_1 != c_2:
                break
        else:
            print("Yes")
            sys.exit()
    print("No")
    
    
if __name__=='__main__':
    main()