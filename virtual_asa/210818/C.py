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
    
    n = int(input())
    V = list(map(int,input().split()))
    V_odd = [0]*(n//2)
    V_even = [0]*(n//2)
    for i, v in enumerate(V):
        if i%2:
            V_odd[i//2] = v 
        else:
            V_even[i//2] = v 
    Vo_c = Counter(V_odd)
    Ve_c = Counter(V_even)
    # print(Vo_c.items())
    # print(Ve_c.items())
    Vo_c_m2 = Vo_c.most_common(2) 
    Ve_c_m2 = Ve_c.most_common(2) 
    if Vo_c_m2[0][0] != Ve_c_m2[0][0]:
        print(n - Vo_c_m2[0][1] - Ve_c_m2[0][1])
    else:
        if Vo_c_m2[0][1] > Ve_c_m2[0][1]:
            if len(Ve_c.keys()) >= 2:
                print(n - Vo_c_m2[0][1] - Ve_c_m2[1][1])
            else:
                print(n - Vo_c_m2[0][1])
        elif Vo_c_m2[0][1] < Ve_c_m2[0][1]:
            if len(Vo_c.keys()) >= 2:
                print(n - Vo_c_m2[1][1] - Ve_c_m2[0][1])     
            else:
                print(n - Ve_c_m2[0][1])
        else:
            if len(Ve_c.keys()) == 1: # 両方一種類
                print(n//2)
            else:
                if Vo_c_m2[1][1] >= Ve_c_m2[1][1]:
                    print(n - Vo_c_m2[1][1] - Ve_c_m2[0][1])
                else:
                    print(n - Vo_c_m2[0][1] - Ve_c_m2[1][1])

    
    
    
if __name__=='__main__':
    main()