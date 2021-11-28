import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    a=int(input())
    b=int(input())
    c=int(input())
    d=int(input())
    e=int(input())
    print(-(-n//min(a,b,c,d,e))+4)

if __name__=='__main__':
    main()