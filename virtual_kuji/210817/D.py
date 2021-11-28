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
    XYH = [tuple(map(int,input().split())) for i in range(n)]
    XYH.sort(key = itemgetter(2), reverse = True) # 0を最後に
    for c_x in range(101):
        for c_y in range(101):
            # 中心が(cx, cy)にあり高さ0のとき
            pre_dh = inf
            for x, y, h in XYH:
                dh = h + (abs(c_x - x) + abs(c_y - y))
                if h > 0:
                    if pre_dh != inf and pre_dh != dh:
                        break # 矛盾
                    elif pre_dh == inf:
                        pre_dh = dh
                        kari_h = dh
                elif kari_h > abs(c_x - x) + abs(c_y - y):
                    break
            else:
                print(c_x, c_y , kari_h)
                sys.exit()
    
if __name__=='__main__':
    main()