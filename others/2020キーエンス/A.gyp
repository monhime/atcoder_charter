import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    h=int(input())
    w=int(input())
    n=int(input())
    print(-(-n//max(h,w)))

if __name__=='__main__':
    main()