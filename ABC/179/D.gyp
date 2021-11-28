import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n, k = map(int,input().split())
    mod = 998244353
    LR = [tuple(map(int,input().split())) for i in range(k)]
    LR.sort()
    DP = [0] * (n + 1)#i(0-)番目まで行く方法f_iについて、f_i-f_(i-1)
    DP[1] = 1
    DP[2] = -1
    f = 0
    for i in range(1, n + 1):
        f = (f + DP[i])%mod
        for l, r in LR:
            if i + l > n:
                break
            DP[i + l] = (DP[i + l] + f)%mod
            if i + r + 1 > n:
                break
            DP[i + r + 1] = (DP[i + r + 1] - f)%mod
    print(f%mod)

        





if __name__=='__main__':
    main()