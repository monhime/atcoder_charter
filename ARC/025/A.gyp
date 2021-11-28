import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    D=[int(_) for _ in input().split()]
    J=[int(_) for _ in input().split()]
    ans=0
    for i in range(7):
        ans+=max(D[i],J[i])
    print(ans)

if __name__=='__main__':
    main()