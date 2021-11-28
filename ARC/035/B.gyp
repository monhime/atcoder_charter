import sys
def input(): return sys.stdin.readline().rstrip()
from collections import Counter
def mod_fra(n, mod, a=1):
    for i in range(1,n+1):
        a=a*i%mod
    return a
def main():
    mod=10**9+7
    n=int(input())
    T=[int(input()) for _ in range(n)]
    T.sort()
    ans1,cur=0,0
    for t in T:
        cur+=t
        ans1+=cur
    ans=1
    for x in list(Counter(T).values()):
        ans*=mod_fra(x,mod)
    print(ans1)
    print(ans%mod)

if __name__=='__main__':
    main()