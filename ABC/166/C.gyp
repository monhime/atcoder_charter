import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,m=map(int,input().split())
    H=[int(_) for _ in input().split()]
    HH= [0]*n

    for i in range(m):
        a,b=map(int,input().split())
        HH[a-1]=max(HH[a-1],H[b-1])
        HH[b-1]=max(HH[b-1],H[a-1])
    ans=0
    for i,hh in enumerate(HH):
        if H[i]>hh or hh==0:
            ans+=1
    print(ans)

if __name__=='__main__':
    main()