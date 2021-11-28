import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    h=int(input())
    w=int(input())
    print((n-h+1)*(n-w+1))

if __name__=='__main__':
    main()