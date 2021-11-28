import sys
def input(): return sys.stdin.readline().rstrip()
from collections import defaultdict
def main():
    n,m=map(int,input().split())
    ac=[False]*n
    wa=[0]*n
    pena=0
    for i in range(m):
        k,s=input().split()
        k=int(k)-1
        if s=="WA":wa[k]+=1
        elif ac[k]:continue
        else:
            ac[k]=True
            pena+=wa[k]
    print(sum(ac),pena)


if __name__=='__main__':
    main()