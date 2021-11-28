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
    
    h, w, x, y  = map(int,input().split())
    x -= 1
    y -= 1
    S = [input() for _ in range(h)]
    ans = 1 # 自分
    for i in range(x + 1, h): # 下方向
        if S[i][y] == ".":
            ans += 1
        else:
            break        
    for i in range(x - 1, -1, -1): # 上方向
        if S[i][y] == ".":
            ans += 1
        else:
            break 
    for j in range(y + 1, w): # 右方向
        if S[x][j] == ".":
            ans += 1
        else:
            break        
    for j in range(y - 1, -1, -1): # 左方向
        if S[x][j] == ".":
            ans += 1
        else:
            break 
    print(ans)

if __name__=='__main__':
    main()