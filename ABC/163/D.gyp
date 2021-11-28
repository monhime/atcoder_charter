import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,k=map(int,input().split())
    ans=0
    for x in range(k,n+2):
        ans+=(1+((n*(n+1)//2-(n-x)*(n-x+1)//2)/x-(x*(x-1)//2)/x)*x)%(10**9+7)
    print(int(ans)%(10**9+7))

if __name__=='__main__':
    main()