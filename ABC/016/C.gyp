import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,m=map(int,input().split())
    C=[[0]*n for _ in range(n)]
    for i in range(m):
        a,b=map(int,input().split())
        C[a-1][b-1]=1
        C[b-1][a-1]=1 
    for i in range(n):
        ans=0
        set_c=set()
        for j in range(n):
            if C[i][j]==1:
                for k,cc in enumerate(C[j]):
                    if cc==1 and k!=i and C[i][k]!=1:
                        set_c.add(k)
        print(len(set_c))

if __name__=='__main__':
    main()