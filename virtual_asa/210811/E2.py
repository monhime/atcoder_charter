import sys
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
def input(): return sys.stdin.readline().rstrip()

S_AGCT = "AGCT"
def contain(s):
    if s[:3] == "AGC":
        return True
    if s[1:] == "AGC":
        return True
    return False

def add(s, c):
    res = s + c
    if contain(res):
        return " "

    for i in range(3):
        if i + 2 > 3:
            tes = res[:i] + res[i + 2:i: -1] 
        else:
            tes = res[:i] + res[i + 2:i: -1] + res[i + 2:]     
        if contain(tes):
            return " "
    
    return res[1:]
    
def main():
    mod = 10**9 + 7
    
    n = int(input())

    dp = dict()
    dp["###"] = 1

    for i in range(n):
        pd = dict()
        for p in dp.keys():
            for c in S_AGCT:
                next = add(p, c)
                if next != " ":
                    pd[next] = (pd.get(next, 0) + dp[p])%mod
        dp, pd = pd, dp
        print(dp)
    ans = 0
    for dp_i in dp.values():
        ans = (ans + dp_i) % mod
    print(ans)
    
if __name__=='__main__':
    main()