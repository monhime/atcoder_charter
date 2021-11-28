import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    m,n,N=map(int,input().split())
    ans=N
    while N>=m:
        x=N//m*n
        ans+=x
        N=x+N-N//m*m
    print(ans)

if __name__=='__main__':
    main()