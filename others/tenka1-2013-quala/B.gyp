import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    ans=0
    for i in range(n):
        a=[int(_) for _ in input().split()]
        if sum(a)<20:
            ans+=1
    print(ans)
        

if __name__=='__main__':
    main()