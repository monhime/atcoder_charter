import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    R,G,B,n=map(int,input().split())
    ans=0
    for r in range(n//R+1):
        for g in range((n-r*R)//G+1):
            if (n-r*R-g*G)%B==0:
                ans+=1
    print(ans)


if __name__=='__main__':
    main()