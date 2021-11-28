import sys
def input(): return sys.stdin.readline().rstrip()
from itertools import product
def main():
    n,k=map(int,input().split())
    T=[[int(_) for _ in input().split()] for i in range(n)]
    pro_lis=list(product(range(k),repeat=n))
    for pro in pro_lis:
        ans=T[0][pro[0]]
        if n>1:
            for i,t in enumerate(T[1:],1):
                ans^=t[pro[i]]
        if ans==0:
            print("Found")
            break
    else:
        print("Nothing")

if __name__=='__main__':
    main()