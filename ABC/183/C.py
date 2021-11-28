import sys
def input(): return sys.stdin.readline().rstrip()
from itertools import permutations
def main():
    n, k = map(int,input().split())
    T = [[int(_) for _ in input().split()] for i in range(n)]
    Move = list(permutations(range(1, n))) # 都市0以外の行き方（）
    ans = 0
    for move in Move:
        cunt_t = T[0][move[0]]
        for i in range(n - 2):
            cunt_t += T[move[i]][move[i + 1]]
        cunt_t += T[move[-1]][0]
        if cunt_t == k:
            ans += 1
    print(ans)

if __name__=='__main__':
    main()