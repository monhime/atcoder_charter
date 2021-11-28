import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    x,y=map(int,input().split())
    for n in range(x+1):
        m=x-n
        if 2*n+4*m==y:
            print("Yes")
            sys.exit()
    print("No")

if __name__=='__main__':
    main()