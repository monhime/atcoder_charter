import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    A=[int(input())for _ in range(n)]
    if A[0]!=0:
        print(-1)
        sys.exit()
    dp=[0]*n
    for i,a in enumerate(A[1:],1):
        if a>=A[i-1]+2:
            print(-1) 
            sys.exit()
        elif a==A[i-1]+1:
            dp[i]=1
        else:
            dp[i]=a
    print(sum(dp))

if __name__=='__main__':
    main()