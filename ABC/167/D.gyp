import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,k=map(int,input().split())
    A=list(map(int,input().split()))
    if A[0]==1:
        print(1)
        sys.exit()
    cur_a=1
    cunt=0
    visited=[False]*n
    visited[0]=True
    route=[1]
    for _ in range(k):
        next_a=A[cur_a-1]
        if visited[next_a-1]:
            loop=len(route)-route.index(next_a)
            cunt-=loop-1
            break
        cur_a=next_a
        cunt+=1
        route.append(cur_a)
        visited[cur_a-1]=True
    else:
        print(next_a)
        sys.exit()
    #print(route)
    #rint(cunt,loop)
    k-=cunt
    k=k%loop
    #print(k)
    print(route[cunt+k])
    

if __name__=='__main__':
    main()