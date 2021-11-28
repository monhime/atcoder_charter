import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    A=[int(_) for _ in input().split()]
    B=[0]*n
    for i in range(n-1,-1,-1):
        x=2*(i+1)
        other=0
        while x<=n:
            other+=B[x-1]
            x+=i+1
        if other%2==A[i]:
            B[i]=0
        else:
            B[i]=1
    print(sum(B))
    print(*[int(i+1) for i,x in enumerate(B) if x==1])

if __name__=='__main__':
    main()