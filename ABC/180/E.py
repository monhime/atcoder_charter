import sys
def input(): return sys.stdin.readline().rstrip()
from collections import deque
import heapq
def main():
    n = int(input())
    XYZ = [[int(_) for _ in input().split()] for i in range(n)]

    dp = [[10**9]*(1<<n) for _ in range(n)] #現在の都市がi、1つ前まで訪問済みの集合S
    dp[0][0] = 0
    for s in range(1<<n): #訪問済みの町の集合å
        for j in range(n): #遷移元の町
            if dp[j][s] == 10**9: #遷移元にいる状態が無い→除外
                continue
            for i in range(n): #現在の町 
                if (s >> i) & 1: #まだ行ったことが無いはず
                    continue
                cost = abs(XYZ[j][0] - XYZ[i][0]) + abs(XYZ[j][1] - XYZ[i][1]) + max(0, XYZ[j][2] - XYZ[i][2])
                dp[i][s | (1 << i)] = min(dp[i][s | (1 << i)], dp[j][s] + cost)
    print(dp[0][(1 << n) - 1])

if __name__=='__main__':
    main()