import sys
def input(): return sys.stdin.readline().rstrip()
import fractions
def main():
    n,m=map(int,input().split())
    s=input()
    t=input()
    ans=-1
    if n==m:
        if s==t:
            ans=n
    else:
        gcd_nm=fractions.gcd(n,m)
        for i in range(gcd_nm):
            if s[n//gcd_nm*i]!=t[m//gcd_nm*i]:
                break
        else:
            ans=n*m//gcd_nm
    print(ans)
     


if __name__=='__main__':
    main()