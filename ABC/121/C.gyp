import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,m=map(int,input().split())
    C=[tuple(map(int,input().split())) for i in range(n)]
    C.sort()
    honsu=m
    cost=0
    for i,c in enumerate(C):
        cost+=c[0]*min(honsu,c[1])
        honsu-=c[1]
        if honsu<=0:
            break
    print(cost)
if __name__=='__main__':
    main()