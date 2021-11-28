import sys
def input(): return sys.stdin.readline().rstrip()
import heapq
def main():
    n,k=map(int,input().split())
    V=list(map(int,input().split()))
    ans=0
    for a in range(min(k+1,n+1)):
        for b in range(min(k-a,n-a)+1):
            cd=k-(a+b)
            H=[]
            sum_V=0
            for i in range(n):
                v=V[i]
                if i+1<=a or i>=n-b:
                    sum_V+=v
                    if v<0:
                        heapq.heappush(H,V[i])
            while H and cd>0:
                sum_V-=heapq.heappop(H)
                cd-=1
            ans=max(sum_V,ans)
    print(ans)


if __name__=='__main__':
    main()