import sys
def input(): return sys.stdin.readline().rstrip()
from collections import deque
def main():
    n=int(input())
    graph=[[]for _ in range(n)]
    for i in range(n-1):
        a,b=map(int,input().split())
        graph[a-1].append(b-1)
        graph[b-1].append(a-1)
    C=list(map(int,input().split()))
    C.sort(reverse=True)#頂点の値が大きい順に
    node_c=[0]*n #各頂点の値 0なら初めて
    node_c[0]=C[0]
    queue=deque([0])
    i=1
    while queue:
        node=queue.popleft()
        for xnode in graph[node]:
            if node_c[xnode]>0:continue
            node_c[xnode]=C[i]
            i+=1
            queue.append(xnode)
    print(sum(C[1:]))
    print(' '.join(map(str,node_c)))

if __name__=='__main__':
    main()