import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    A=[int(input())for _ in range(n)]
    A.sort()
    ans1=0
    if n%2==0:
        ans1=(2*sum(A[n//2:])-A[n//2])-(2*sum(A[:n//2])-A[n//2-1])
    else:
        ans1=(2*sum(A[n//2:])-A[n//2]-A[n//2+1])-2*sum(A[:n//2])
    ans2=0
    if n%2==0:
        ans2=(2*sum(A[n//2:])-A[n//2])-(2*sum(A[:n//2])-A[n//2-1])
    else:
        ans2=2*sum(A[n//2+1:])-(2*sum(A[:n//2+1])-A[n//2-1]-A[n//2])      
    print(max(ans1,ans2))

if __name__=='__main__':
    main()