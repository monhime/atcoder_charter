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
    
    a, b, c = map(int,input().split())
    if c % 2 == 0:
        if abs(a) < abs(b):
            print("<")
        elif abs(a) == abs(b):
            print("=")
        else:
            print(">")
    else: # c が奇数
        if a < 0:
            if b < 0:
                if a < b: 
                    print("<")
                elif a == b:
                    print("=")
                else:
                    print(">")
            else:
                print("<")
        elif a == 0:
            if b > 0:
                print("<")
            elif b == 0:
                print("=")
            else:
                print(">")
        else:
            if b > 0:
                if a < b: 
                    print("<")
                elif a == b:
                    print("=")
                else:
                    print(">")
            else:
                print(">")
    
    
if __name__=='__main__':
    main()