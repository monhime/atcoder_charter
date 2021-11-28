import sys
def input(): return sys.stdin.readline().rstrip()
from collections import Counter
def main():
    n,c=map(int,input().split())
    A=[int(input())for _ in range(n)]
    ans=10**100
    for ne in range(1,11):
        for no in range(1,11):
            if ne==no:continue
            cunt=0
            for i in range(n):
                if i%2==0 and A[i]!=ne:
                    cunt+=1
                elif i%2==1 and A[i]!=no:
                    cunt+=1
            ans=min(ans,cunt)
    print(ans*c)


if __name__=='__main__':
    main()
