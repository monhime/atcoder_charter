import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,k=map(int,input().split())
    r,s,p=map(int,input().split())
    T=input()
    T_lis=[False]*n
    ans=0
    for i,t in enumerate(T):
        if i-k>=0:
            if T[i-k]==t and T_lis[i-k]:
                continue
        if t=='r':
            ans+=p
        elif t=='s':
            ans+=r
        else:
            ans+=s
        T_lis[i]=True
    print(ans)


if __name__=='__main__':
    main()