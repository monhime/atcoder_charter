import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    pi=3.1415926535
    r,d=map(int,input().split())
    print(2*pi**2*r**2*d)

if __name__=='__main__':
    main()