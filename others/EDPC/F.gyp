import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    s=input()
    len_s=len(s)
    t=input()
    len_t=len(t)
    dp=[[0]*(len_t+1) for _ in range(len_s+1)] # sのi文字目までについて，jを使うときに
    for i in range(1,len_s+1):
        for j in range(1,len_t+1):
            if s[i-1]==t[j-1]:
                dp[i][j]=dp[i-1][j-1]+1
            else:
                dp[i][j]=max(dp[i-1][j],dp[i][j-1])
    len_ans=dp[len_s][len_t]
    i,j=len_s,len_t
    ans=""
    while len_ans:
        if s[i-1]==t[j-1]:
            ans+=s[i-1]
            i-=1
            j-=1
            len_ans-=1
        elif dp[i][j]==dp[i-1][j]:
            i-=1
        else:
            j-=1
    print(ans[::-1])
if __name__=='__main__':
    main()