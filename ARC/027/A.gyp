import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    h,m=map(int,input().split())
    print(60-m+60*(17-h))

if __name__=='__main__':
    main()