import sys
def input(): return sys.stdin.readline().rstrip()
import heapq
def main():
    n,m=map(int,input().split())
    AB=[tuple(map(int,input().split())) for i in range(n)]
    AB.sort(reverse=True)
    H=[]
    ans=0
    for i in range(1,m+1):
        while AB and AB[-1][0]<=i:
            a,b=AB.pop()
            heapq.heappush(H,(-b,a))
        if H:
            bb,aa=heapq.heappop(H)
            ans-=bb
    print(ans)

if __name__=='__main__':
    main()