import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,k=map(int,input().split())
    if n>=2*k-1:print("YES")
    else:print("NO")

if __name__=='__main__':
    main()