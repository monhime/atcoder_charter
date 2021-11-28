import sys
def input(): return sys.stdin.readline().rstrip()
from fractions import gcd
def prime_fact(m):
    pf={}
    for i in range(2,int(m**0.5)+1):
        while m%i==0:
            pf[i]=pf.get(i,0)+1
            m//=i
    if m>1:pf[m]=1
    return list(pf)
def main():
    a,b=map(int,input().split())
    print(1+len(prime_fact(gcd(a,b))))

if __name__=='__main__':
    main()