import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    K=[int(_) for _ in input().split()]
    A=[0]*n
    A[0]=K[0]
    for i in range(1,n):
        if A[i-1]==K[i-1]:
            if i==n-1:
                A[i]=K[i-1]
            else:
                A[i]=min(K[i-1],K[i])
        else:
            A[i]=K[i-1]
    print(*A)

if __name__=='__main__':
    main()