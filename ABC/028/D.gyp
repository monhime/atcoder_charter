import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,k=map(int,input().split())
    print(((k-1)*(n-k)*6+1+(n-1)*3)/n**3)

if __name__=='__main__':
    main()