import sys
def input(): return sys.stdin.readline().rstrip()
from functools import reduce
def mod_comb4(n,r,mod=10**9+7):
    if r==1:return n
    elif r==0:return 1
    else:
        num=reduce(lambda x,y:x*y%mod,range(n,n-r,-1))
        den=reduce(lambda x,y:x*y%mod,range(1,r+1))
        return num*pow(den,mod-2,mod)%mod
def main():
    x,y=map(int,input().split())
    mod=10**9+7
    n=2*x-y
    m=2*y-x
    if n%3==0 and m%3==0 and n>=0 and m>=0:
        print(mod_comb4(n//3+m//3,n//3,mod))
    else:
        print(0)


if __name__=='__main__':
    main()