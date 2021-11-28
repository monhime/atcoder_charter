import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,a,b,c=map(int,input().split())
    L=[int(input())for _ in range(n)]
    INF=10**9
    def dfs(cur,aa,bb,cc):
        if cur==n:
            return abs(aa-a)+abs(bb-b)+abs(cc-c)-30 if aa*bb*cc>0 else INF
        ret0=dfs(cur+1,aa,bb,cc)
        ret1=dfs(cur+1,aa+L[cur],bb,cc)+10
        ret2=dfs(cur+1,aa,bb+L[cur],cc)+10
        ret3=dfs(cur+1,aa,bb,cc+L[cur])+10
        return min(ret0,ret1,ret2,ret3)
    print(dfs(0,0,0,0))

if __name__=='__main__':
    main()