import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,k=map(int,input().split())
    print(min(n%k,k-n%k))

if __name__=='__main__':
    main()