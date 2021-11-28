import sys
def input(): return sys.stdin.readline().rstrip()
from collections import Counter
def main():
    n,m=map(int,input().split())
    name=input()
    kit=input()
    name_c=Counter(name)
    kit_c=Counter(kit)
    name_ci=name_c.items()
    ans=0
    for name_cii in list(name_ci):
        if kit_c[name_cii[0]]==0:
            print(-1)
            break
        ans=max(ans,-(-name_cii[1]//kit_c[name_cii[0]]))
    else:
        print(ans)

if __name__=='__main__':
    main()