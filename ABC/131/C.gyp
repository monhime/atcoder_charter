import sys
import fractions
def input(): return sys.stdin.readline().rstrip()
def cunt_multi(a,b,n):
    if b%n<=(b-a+1)%n-1:
        return (b-a+1)//n+1
    else:
        return (b-a+1)//n

def lcm(a,b):
    f=a*b//fractions.gcd(a,b)
    return f

def main():
    a,b,c,d=map(int,input().split())
    print(b-a+1-cunt_multi(a,b,c)-cunt_multi(a,b,d)+cunt_multi(a,b,lcm(c,d)))

if __name__=='__main__':
    main()