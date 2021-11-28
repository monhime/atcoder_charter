import sys
def input(): return sys.stdin.readline().rstrip()
from collections import deque
def main():
    n=int(input())
    XY=[tuple(map(int,input().split())) for i in range(n-1)]
    graph=[[]for _ in range(n)]
    for x,y in XY:
        graph[x-1].append(y-1)
        graph[y-1].append(x-1)
    queue=deque([0])
    visited=[False]*n
    use=[False]*n #子のノードかどうか。計算したらTrueに。
    #i番目に訪れた頂点までについて，i番目の頂点を白に塗る塗り方，黒
    dp=[[0,0] for _ in range(n)]
    mod=10**9+7
    while queue:
        node=queue[-1] #末尾の要素がvisited→葉に着いた
        if not visited[node]:
            visited[node]=True
            for xnode in graph[node]:
                if visited[xnode]:continue
                queue.append(xnode)
        else:
            queue.pop()
            b,w=1,1 #葉の場合1,1になる
            for xnode in graph[node]:   
                if use[xnode]:
                    w=w*(dp[xnode][0]+dp[xnode][1])%mod
                    b=b*dp[xnode][0]%mod 
            dp[node][0]=w%mod
            dp[node][1]=b%mod 
            use[node]=True
    print(sum(dp[0])%mod)

if __name__=='__main__':
    main()