import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    A=[int(_) for _ in input().split()]
    ans=0
    for i in range(n):
        ans+=A[-1-i]*2**i
    print(ans)

if __name__=='__main__':
    main()