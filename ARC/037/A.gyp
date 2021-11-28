import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    M=[int(_) for _ in input().split()]
    ans=0
    for i in range(n):
        ans+=max(80-M[i],0)
    print(ans)


if __name__=='__main__':
    main()