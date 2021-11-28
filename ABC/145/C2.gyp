import sys
from math import sqrt
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    A =[[int(_) for _ in input().split()] for i in range(n)]
    ans=0
    for i in range(n-1):
        for j in range(i+1,n):
            ans+=sqrt((A[i][0]-A[j][0])**2+(A[i][1]-A[j][1])**2)
    print(ans*2/n)
if __name__=='__main__':
    main()