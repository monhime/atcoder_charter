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
    S = [[0] * (len(s) + 1) for _  in range(8)]
    ans = 0
    for i, ss in enumerate(s):
        for j in range( 8):
            S[j][i + 1] = S[j][i]
        if ss == "c":
            S[0][i + 1] += 1
        if ss == "h":
            S[1][i + 1] += S[0][i] # chが作れる
        if ss == "o":
            S[2][i + 1] += S[1][i] #choが作れる
        if ss == "k":
            S[3][i + 1] += S[2][i] 
        if ss == "u":
            S[4][i + 1] += S[3][i]
        if ss == "d":
            S[5][i + 1] += S[4][i] 
        if ss == "a":
            S[6][i + 1] += S[5][i] 
        if ss == "i":
            S[7][i + 1] += S[6][i] 
    print(S[7][len(s)] % mod)

if __name__=='__main__':
    main()