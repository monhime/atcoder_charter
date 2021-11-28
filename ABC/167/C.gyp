import sys
def input(): return sys.stdin.readline().rstrip()
from itertools import product
def main():
    n,m,x=map(int,input().split())
    CA=[[int(_) for _ in input().split()] for i in range(n)]
    ans=10**10
    n_lis=list(product([True,False],repeat=n))
    for comb in n_lis:
        cunt=0
        A=[0]*m
        for i,ca in enumerate(CA):
            if comb[i]:
                cunt+=ca[0]
                for j,aa in enumerate(ca[1:]):
                    A[j]+=aa
        for a in A:
            if a<x:
                break
        else:
            ans=min(ans,cunt)
    if ans==10**10:
        print(-1)
    else:
        print(ans)

if __name__=='__main__':
    main()