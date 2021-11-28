import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n, x, t = map(int,input().split())
    print(-t*(-n//x))

if __name__=='__main__':
    main()