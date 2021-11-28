import sys
def input(): return sys.stdin.readline().rstrip()
import math
def main():
    a,b,x=map(int,input().split())
    if x==a**2*b:
        print(0)
        sys.exit()
    if x<=a**2*b/2:
        print(90.0-math.degrees(math.atan((2*x)/(a*b**2))))
    else:
        z=2*x/a**2-b
        print(90.0-math.degrees(math.atan(a/(b-z))))

if __name__=='__main__':
    main()