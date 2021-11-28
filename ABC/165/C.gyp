import sys
def input(): return sys.stdin.readline().rstrip()
from itertools import combinations_with_replacement
def main():
    n,m,q=map(int,input().split())
    lis=list(combinations_with_replacement(range(1,m+1),n))
    ans=0
    Q=[[int(_) for _ in input().split()] for i in range(q)]
    for l in lis:
        cunt=0
        for q in Q:
            if int(l[q[1]-1])-int(l[q[0]-1])==q[2]:
                cunt+=q[3]
        ans=max(ans,cunt)
    print(ans)
if __name__=='__main__':
    main()