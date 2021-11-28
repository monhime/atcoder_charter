import sys
def input(): return sys.stdin.readline().rstrip()
def prime_fact(m):
    pf={}
    for i in range(2,int(m**0.5)+1):
        while m%i==0:
            pf[i]=pf.get(i,0)+1
            m//=i
    if m>1:pf[m]=1
    return pf
def main():
    n,p=map(int,input().split())
    p_dict=prime_fact(p)
    ans=1
    for pp in p_dict.items():
        ans*=pp[0]**(pp[1]//n)
    print(ans)


if __name__=='__main__':
    main()