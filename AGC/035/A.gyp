import sys
def input(): return sys.stdin.readline().rstrip()
from collections import Counter

def main():
    n=int(input())
    A=[int(_) for _ in input().split()]
    ac=Counter(A)
    aci=list(ac.items())
    aci.sort()
    ans="No"
    if aci[0]==(0,n):
        ans="Yes"
    elif n%3==0 and len(aci)==2:
        if aci[0]==(0,n//3) and aci[1][1]==n//3*2:
            ans="Yes"
    elif n%3==0 and len(aci)==3:
        if aci[0][1]==aci[1][1] and aci[1][1]==aci[2][1] and aci[0][0]^aci[1][0]^aci[2][0]==0:
            ans="Yes"  
    print(ans)


if __name__=='__main__':
    main()