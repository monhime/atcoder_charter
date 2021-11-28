import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    A=list(map(int,input().split()))
    cunt=[0]*(n+1)
    cunt[0]=3
    ans=1
    mod=10**9+7
    for a in A:
        ans=ans*cunt[a]%mod
        if ans==0:break
        cunt[a+1]+=1
        cunt[a]-=1
    print(ans)
    

if __name__=='__main__':
    main()