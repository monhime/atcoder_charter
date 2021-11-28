import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    s=input()
    len_s=len(s)
    mod=10**9+7
    dp=[[0]*13 for _ in range(len_s+1)] #i(1-)桁目までについて，13で割った余り
    dp[0][0]=1
    for i in range(len_s):
        if s[i]=="?":
            for j in range(13):
                for k in range(10):
                    dp[i+1][(10*j+k)%13]+=dp[i][j]%mod
        else:
            c=int(s[i])
            for j in range(13):
                dp[i+1][(10*j+c)%13]=dp[i][j]
        for j in range(13):
            dp[i+1][j]%=mod
    print(dp[len_s][5])

if __name__=='__main__':
    main()