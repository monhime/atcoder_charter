import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,m,d=map(int,input().split())
    ans=0
    if d==0:
        print((m-1)/n)
    else:
        print(2*(n-d)*(m-1)/n**2)

if __name__=='__main__':
    main()