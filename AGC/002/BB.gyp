import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,m=map(int,input().split())
    lis=[1]*n
    rlis=[False]*n
    rlis[0]=True
    for i in range(m):
        x,y=map(int,input().split())
        x-=1
        y-=1
        if lis[x]==1:
            lis[x]-=1
            lis[y]+=1
            if rlis[x]:
                rlis[x]=False
                rlis[y]=True
        else:
            lis[x]-=1
            lis[y]+=1
            if rlis[x]:
                rlis[y]=True
    print(rlis.count(True))


if __name__=='__main__':
    main()