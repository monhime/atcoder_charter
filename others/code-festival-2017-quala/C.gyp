import sys
def input(): return sys.stdin.readline().rstrip()
from collections import Counter
def main():
    h,w=map(int,input().split())
    s=""
    for _ in range(h):
        s+=input()
    sc=list(Counter(s).values())
    cunt_1=(h%2)*(w%2)
    cunt_2=(h%2)*(w//2)+(w%2)*(h//2)
    cunt_4=(h//2)*(w//2)
    #print(sc)
    for i,scc in enumerate(sc):
        if scc>=4:
            x=min(scc//4,cunt_4)
            sc[i]-=x*4
            cunt_4-=x
    for i,scc in enumerate(sc):
        if scc>=2:
            x=min(scc//2,cunt_2)
            sc[i]-=x*2
            cunt_2-=x
    for i,scc in enumerate(sc):
        if scc>=1:
            x=min(scc,cunt_1)
            sc[i]-=x
            cunt_1-=x
    print("Yes" if all(scc==0 for scc in sc) else "No")

        

if __name__=='__main__':
    main()