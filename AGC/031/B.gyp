import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    mod=10**9+7
    stone_last_pos=[-1]*(2*10**5+1)
    dp=[0]*(n+1)
    dp[0]=1
    for i in range(1,n+1):
        c=int(input())
        place=stone_last_pos[c]
        if place==i-1 or place==-1:
            dp[i]=dp[i-1]
        else:
            dp[i]=(dp[i-1]+dp[place])%mod
        stone_last_pos[c]=i
    print(dp[n])


if __name__=='__main__':
    main()