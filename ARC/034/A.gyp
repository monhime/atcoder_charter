import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    ans=0
    for i in range(n):
        a,b,c,d,e=map(int,input().split())
        ans=max(ans,a+b+c+d+e*110/900)
    print(ans)

if __name__=='__main__':
    main()