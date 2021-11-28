import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    B=[int(_) for _ in input().split()]
    ans=B[0]+B[-1]
    for i in range(n-1):
        ans+=min(B[i],B[i+1])
    print(ans)
if __name__=='__main__':
    main()