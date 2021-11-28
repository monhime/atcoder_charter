import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,h,w=map(int,input().split())
    ans=0
    for i in range(n):
        a,b=map(int,input().split())
        if a>=h and b>=w:
            ans+=1
    print(ans)

if __name__=='__main__':
    main()