import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    a,b,m=map(int,input().split())
    A=[int(_) for _ in input().split()]
    B=[int(_) for _ in input().split()]
    ans=min(A)+min(B)
    for i in range(m):
        x,y,c=map(int,input().split())
        ans=min(ans,A[x-1]+B[y-1]-c)
    print(ans)

if __name__=='__main__':
    main()