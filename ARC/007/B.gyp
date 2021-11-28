import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,m=map(int,input().split())
    lis=list(range(1,n+1))
    now=0
    for i in range(m):
        x=int(input())
        if x!=now:
            now,lis[lis.index(x)]=lis[lis.index(x)],now
    for i in range(n):
        print(lis[i])

if __name__=='__main__':
    main()