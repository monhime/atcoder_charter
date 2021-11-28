import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n, w = map(int,input().split())
    print(n//w)

if __name__=='__main__':
    main()