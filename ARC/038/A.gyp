import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    A=[int(_) for _ in input().split()]
    A.sort(reverse=True)
    ans=0
    for i in range((n+1)//2):
        ans+=A[2*i]
    print(ans)

if __name__=='__main__':
    main()