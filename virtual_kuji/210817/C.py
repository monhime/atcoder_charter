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
    
    s = input()
    n_s = len(s)
    k = int(input())
    cunt_s = 1 # 先頭側連続文字列 
    if n_s >= 2 and s[0] == s[1]: 
        for i in range(n_s - 1):
            if s[i] == s[i + 1]:
                cunt_s += 1
            else:
                break
    if cunt_s == n_s:
        print(n_s*k//2)
        sys.exit()
    cunt_l = 1 # 末尾側連続文字列 
    if n_s >= 2 and s[-1] == s[-2]: 
        for i in range(n_s - 1, 0, -1):
            if s[i - 1] == s[i]:
                cunt_l += 1
            else:
                break
    group_mid = 0 # 中間で連続文字列のグループに必要な処理
    cunt_mid = 1 # 中間で連続文字列のグループ数
    for i in range(cunt_s, n_s - cunt_l - 1):
        if s[i] == s[i + 1]:
            cunt_mid += 1
        else:
            group_mid += cunt_mid//2
            cunt_mid = 1
    else:
        group_mid += cunt_mid//2

    # print(cunt_s, cunt_l, group_mid)
    if s[0] == s[-1]:
        print(cunt_s//2 + group_mid*k + (cunt_s + cunt_l)//2*(k - 1) + cunt_l//2 )
    else:
        print(cunt_s//2*k + group_mid*k  + cunt_l//2*k)
    
    
if __name__=='__main__':
    main()