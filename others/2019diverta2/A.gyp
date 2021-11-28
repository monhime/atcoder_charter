import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,k=map(int,input().split())
    if k==1:print(0)
    else:print(n-k)

if __name__=='__main__':
    main()