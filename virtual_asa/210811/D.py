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
    
    n, c, k = map(int,input().split())
    T = [int(input())for _ in range(n)]
    T.sort()
    ans = 1 #バスの台数
    start_idx = 0 # 乗せる人間
    while True:
        def is_good(mid):
            if T[mid] > T[start_idx] + k:
                return True
            else:
                return False
        # [bad, good)に求める解がある。
        # xxxxoooo，bad：境界左側、good：境界右側
        # good = bad+1で終了し、好きな方を取り出す
        def bi_search(bad, good):
            while good - bad > 1:
                mid = (bad + good)//2
                if is_good(mid):
                    good = mid
                else:
                    bad = mid
            return good
            # return bad
        next_idx = bi_search(start_idx, n) # 次のバスに乗る人
        if next_idx - start_idx > c:
            start_idx += c
            ans += 1
        elif  next_idx == n:
            break
        else:
            ans += 1
            start_idx = next_idx
    print(ans)
    
if __name__=='__main__':
    main()