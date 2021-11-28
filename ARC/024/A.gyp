import sys
def input(): return sys.stdin.readline().rstrip()
from collections import Counter
def main():
    l,r=map(int,input().split())
    L=[int(_) for _ in input().split()]
    R=[int(_) for _ in input().split()]
    l_c=Counter(L)
    r_c=Counter(R)
    ans=0
    for ll in l_c.keys():
        ans+=min(r_c[ll],l_c[ll])
    print(ans)

if __name__=='__main__':
    main()