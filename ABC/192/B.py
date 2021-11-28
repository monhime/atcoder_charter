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
    for i, _s in enumerate(s):
        if i % 2 == 0 and ord(_s) >= ord('a'):
            continue
        elif i % 2 == 1 and ord(_s) <= ord('Z'):
            continue
        else:
            print("No")
            sys.exit()
    print("Yes")
    
    
if __name__=='__main__':
    main()