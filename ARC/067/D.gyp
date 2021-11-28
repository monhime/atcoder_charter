import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,a,b=map(int,input().split())
    X=list(map(int,input().split()))
    ans=0
    for i in range(n-1):
        ans+=min(a*(X[i+1]-X[i]),b)
    print(ans)


if __name__=='__main__':
    main()