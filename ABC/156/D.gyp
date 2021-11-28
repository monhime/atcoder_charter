import sys
def input(): return sys.stdin.readline().rstrip()

from functools import reduce
def mod_comb4(n,r,mod=10**9+7):
    num=reduce(lambda x,y:x*y%mod,range(n,n-r,-1))
    den=reduce(lambda x,y:x*y%mod,range(1,r+1))
    return num*pow(den,mod-2,mod)%mod
def main():
    n,a,b=map(int,input().split())
    mod=10**9+7
    print((pow(2,n,mod)-1-mod_comb4(n,a)-mod_comb4(n,b))%mod)

if __name__=='__main__':
    main()