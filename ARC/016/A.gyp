import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,m=map(int,input().split())
    if m==1:print(2)
    else:print(1)

if __name__=='__main__':
    main()