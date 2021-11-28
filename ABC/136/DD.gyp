import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    s=input()
    n=len(s)
    cnt=10**5
    m=len(format(cnt, 'b'))
    dp=[[-1 for j in range(n)] for i in range(m+1)]
    for j in range(n):
        if s[j]=='L':
            dp[0][j]=j-1
        else:
            dp[0][j]=j+1
    
    for i in range(m):
        for j in range(n):
            dp[i+1][j]=dp[i][dp[i][j]]
    
    after=[]
    for j in range(n):
        i=0
        nn=cnt
        cur_j=j
        while nn>0:
            if ((nn&1)==1):
                cur_j=dp[i][cur_j]
            nn>>=1
            i+=1
        after.append(cur_j)

    ans=[0]*n
    for j in range(n):
        ans[after[j]] += 1
    print(*ans)

if __name__=='__main__':
    main()