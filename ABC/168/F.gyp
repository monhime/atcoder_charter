import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,m=map(int,input().split())
    ABC=[tuple(map(int,input().split())) for i in range(n)]
    DEC=[tuple(map(int,input().split())) for i in range(m)]
    

if __name__=='__main__':
    main()