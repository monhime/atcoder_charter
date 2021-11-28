import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,m=map(int,input().split())
    X=[int(_) for _ in input().split()]
    if m<=n:
        print(0)
    else:
        X.sort()
        XX=[0]*(m-1)
        for i in range(m-1):
            XX[i]=X[i+1]-X[i]
        XX.sort(reverse=True)
        print(X[-1]-X[0]-sum(XX[:n-1]))

if __name__=='__main__':
    main()