import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    Sx, Sy, Gx, Gy = map(int,input().split())
    print((Sy*(Gx - Sx))/(Sy + Gy) + Sx)

if __name__=='__main__':
    main()