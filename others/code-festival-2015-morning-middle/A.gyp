import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,k,m,r=map(int,input().split())
    S=[int(input())for _ in range(n-1)]
    if k<n:
        S.sort(reverse=True)
        sum_s=sum(S[:k])
        if sum_s//k>=r:
            print(0)
        elif k*r-(sum_s-S[k-1])>m:
            print(-1)
        else:
            print(k*r-(sum_s-S[k-1]))
    else:
        sum_s=sum(S)
        if k*r-sum_s<=0:
            print(0)
        elif k*r-sum_s>m:
            print(-1)
        else:
            print(k*r-sum_s)        

if __name__=='__main__':
    main()