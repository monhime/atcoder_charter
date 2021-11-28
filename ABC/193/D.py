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
    
    n_k = int(input())
    s = input()[:4]
    t = input()[:4]

    win, lose = 0.0, 0.0
    for i in range(1, 10):
        for j in range(1, 10):
            score_t, score_a = 0, 0
            if i !=j and (s.count(str(i))  + t.count(str(i)) + 1 <= n_k) and (s.count(str(j))  + t.count(str(j)) + 1 <= n_k):
                for k in range(1, 10):
                    if k == i:
                        score_t += k*10**(s.count(str(k)) + 1)
                    else:
                        score_t += k*10**s.count(str(k))
                    if k == j:
                        score_a += k*10**(t.count(str(k)) + 1)
                    else:
                        score_a += k*10**t.count(str(k))
                if score_t > score_a:
                    win += (n_k - s.count(str(i))  - t.count(str(i)))*(n_k - s.count(str(j))  - t.count(str(j)))
                else:
                    lose += (n_k - s.count(str(i))  - t.count(str(i)))*(n_k - s.count(str(j))  - t.count(str(j)))
            elif i == j and (s.count(str(i))  + t.count(str(i)) + 2 <= n_k):
                for k in range(1, 10):
                    if k == i:
                        score_t += k*10**(s.count(str(k)) + 1)
                        score_a += k*10**(t.count(str(k)) + 1)
                    else:
                        score_t += k*10**s.count(str(k))
                        score_a += k*10**t.count(str(k))
                if score_t > score_a:
                    win += (n_k - s.count(str(i))  - t.count(str(i)))*(n_k - s.count(str(i))  - t.count(str(i)) - 1)
                else:
                    lose += (n_k - s.count(str(i))  - t.count(str(i)))*(n_k - s.count(str(i))  - t.count(str(i)) - 1)
    print(win/(win + lose))
    
    
if __name__=='__main__':
    main()