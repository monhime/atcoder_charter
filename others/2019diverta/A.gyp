import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,k=map(int,input().split())
    print(n-k+1)

if __name__=='__main__':
    main()