import sys
def input(): return sys.stdin.readline().rstrip()
import heapq
def main():
    n,m=map(int,input().split())
    A=[int(_) for _ in input().split()]
    A=list(map(lambda x:-x,A))
    heapq.heapify(A)
    for _ in range(m):
        x=heapq.heappop(A)
        heapq.heappush(A,-(-x//2))
    print(-sum(A))

if __name__=='__main__':
    main()