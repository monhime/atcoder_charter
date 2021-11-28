import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    A=[int(_) for _ in input().split()]
    cunt,ans=0,0
    min_a=10**9
    for a in A:
        if a<0:
            cunt+=1
            ans+=-a
            min_a=min(-a,min_a)
        else:
            ans+=a
            min_a=min(a,min_a)
    if cunt%2==1:
        print(ans-2*min_a)
    else:
        print(ans)

if __name__=='__main__':
    main()