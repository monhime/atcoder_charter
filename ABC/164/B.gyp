import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    a,b,c,d=map(int,input().split())
    x=-(-c//b)
    y=-(-a//d)
    if x<=y:
        print("Yes")
    else:
        print("No")

if __name__=='__main__':
    main()