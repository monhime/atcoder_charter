import sys
import fractions
def input(): return sys.stdin.readline().rstrip()
import math

def main():
    n,x=map(int,input().split())
    X=[int(_) for _ in input().split()]
    X.append(x)
    X.sort()
    ans=X[1]-X[0]
    for i in range(1,n):
        ans=fractions.gcd(ans,X[i+1]-X[i])
    print(ans)

if __name__=='__main__':
    main()