import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    if n<=1:
        print(1)
        sys.exit()
    a=[0]*(n+1)
    a[0]=1
    a[1]=1
    for i in range(2,n+1):
        a[i]=a[i-2]+a[i-1]
    print(a[-1])
if __name__=='__main__':
    main()