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
    
    n = int(input())
    # x日目には総計x(x+1)//2
    # x(x+1)>=2n

    def is_good(x):
        if x*(x + 1) >= 2 * n:
            return True
        else:
            return False
    #[bad, good)に求める解がある。bad：境界左側、good：境界右側
    #good = bad+1で終了し、好きな方を取り出す
    def bi_search(bad, good):
        while good - bad > 1:
            mid = (bad + good)//2
            if is_good(mid):
                good = mid
            else:
                bad = mid
        return good

    print(bi_search(0, 100000))

    
    
if __name__=='__main__':
    main()