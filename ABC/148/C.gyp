import sys
def input(): return sys.stdin.readline().rstrip()
import fractions
def lcm(a,b):
    f=a*b//fractions.gcd(a,b)
    return f
def main():
    a,b=map(int,input().split())
    print(lcm(a,b))

if __name__=='__main__':
    main()