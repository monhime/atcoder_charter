import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,a,b=map(int,input().split())
    if (b-a)%2==0:print((b-a)//2)
    else:print(min((b+a-1)//2,(2*n-b+1-a)//2))

if __name__=='__main__':
    main()