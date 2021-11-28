import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    X=[int(_) for _ in input().split()]
    sum_x=sum(X)
    ans=0
    if sum_x/n-sum_x//n<0.5:p=sum_x//n
    else:p=sum_x//n+1
    for i in range(n):
        ans+=(X[i]-p)**2
    print(ans)

if __name__=='__main__':
    main()