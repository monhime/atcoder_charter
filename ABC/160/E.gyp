import sys
def input(): return sys.stdin.readline().rstrip()
import heapq
def main():
    x,y,a,b,c=map(int,input().split())
    P=list(map(int,input().split()))
    Q=list(map(int,input().split()))
    R=list(map(int,input().split()))
    P.sort(reverse=True)
    Q.sort(reverse=True)
    R.sort(reverse=True)
    Z=P[:x]+Q[:y]
    heapq.heapify(Z)
    for r in R:
        if Z[0]>=r:
            break
        heapq.heapreplace(Z,r)
    print(sum(Z))

    

if __name__=='__main__':
    main()