def main():
    import sys
    input = sys.stdin.readline

    n,m=map(int,input().split())
    CARD=[0]*(n+1)
    for i in range(m):
        L,R=map(int,input().split())
        CARD[L-1]+=1
        CARD[R]-=1
    ans=0
    for i in range(n):
        if CARD[i]==m:ans+=1
        CARD[i+1]=CARD[i+1]+CARD[i]

    print(ans)

if __name__=='__main__':
    main()