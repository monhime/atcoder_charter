import sys
def input(): return sys.stdin.readline().rstrip()
from bisect import bisect
def main():
    a,b,q=map(int,input().split())
    S=[int(input())for _ in range(a)]
    T=[int(input())for _ in range(b)]

    def dfs(cur,flag1,flag2):
        if flag2==1:
            index_s=bisect(S,cur)
            #print(cur,index_s)
            if index_s>0 and index_s<a:
                if flag1==0:
                    return min(abs(S[index_s-1]-cur),abs(S[index_s]-cur))
                else:
                    return min(dfs(S[index_s-1],0,0)+abs(S[index_s-1]-cur),dfs(S[index_s],0,0)+abs(S[index_s]-cur))
            else:
                if index_s==a:
                    nx=S[-1]
                elif index_s==0:
                    nx=S[0]
                if flag1==1:
                    return dfs(nx,0,0)+abs(nx-cur)
                else:
                    return abs(nx-cur)
        else:
            index_t=bisect(T,cur)
            #print(cur,index_t)
            if index_t>0 and index_t<b:
                if flag1==0:
                    return min(abs(T[index_t-1]-cur),abs(T[index_t]-cur))
                else:
                    return min(dfs(T[index_t-1],0,1)+abs(T[index_t-1]-cur),dfs(T[index_t],0,1)+abs(T[index_t]-cur))
            else:
                if index_t==b:
                    nx=T[-1]
                elif index_t==0:
                    nx=T[0]
                if flag1==1:
                    return dfs(nx,0,1)+abs(nx-cur)
                else:
                    return abs(nx-cur)

    for i in range(q):
        x=int(input())
        print(min(dfs(x,1,1),dfs(x,1,0)))


if __name__=='__main__':
    main()