import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,k=map(int,input().split())
    A=[int(_) for _ in input().split()]
    ans,sum_a,r=0,0,0
    for l in range(n):
        while sum_a<k:
            if r==n:
                break
            sum_a+=A[r]
            r+=1
        if sum_a>=k:
            ans+=n-r+1
            sum_a-=A[l]
    print(ans)

if __name__=='__main__':
    main()