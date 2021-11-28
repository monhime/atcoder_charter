import sys
def input(): return sys.stdin.readline().rstrip()
from collections import Counter
def main():
    n=int(input())
    lis=[]
    ans=0
    for i in range(n):
        s=input()
        s_c=Counter(s)
        s_ct=tuple(sorted(s_c.items()))
        lis.append(s_ct)
    lis_c=Counter(lis)
    for li in lis_c.items():
        x=li[1]
        if x>=2:
            ans+=x*(x-1)//2
    print(ans)

if __name__=='__main__':
    main()