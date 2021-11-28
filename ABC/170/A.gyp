import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    x=list(map(int,input().split()))
    print(x.index(0)+1)

if __name__=='__main__':
    main()