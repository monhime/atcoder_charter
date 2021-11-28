import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    h,w=map(int,input().split())
    S=[input() for _ in range(w)]
    DP=[[0]*w for _ in range(h)]
    if S[0][0]=='#':
        DP[0][0]=1
    for j in range(1,w):
        if S[0][j-1]=='.' and S[0][j]=='#':
            DP[0][j]=DP[0][j-1]+1
        else:
            DP[0][j]=DP[0][j-1]
    for i in range(1,h):
        if S[i-1][0]=='.' and S[i][0]=='#':
            DP[i][0]=DP[i-1][0]+1
        else:
            DP[i][0]=DP[i-1][0]
        for j in range(1,w):
            if S[i-1][j]=='.' and S[i][j]=='#':
                d=DP[i-1][j]+1
            else:
                d=DP[i-1][j]
            if S[i][j-1]=='.' and S[i][j]=='#':
                r=DP[i][j-1]+1
            else:
                r=DP[i][j-1]
            DP[i][j]=min(d,r)
    print(DP[-1][-1])

if __name__=='__main__':
    main()