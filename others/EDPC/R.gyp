import sys
def input(): return sys.stdin.readline().rstrip()
def multi_mat(M1,M2,n,mod=10**9+7):
    ans=[[0]*n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            for k in range(n):
                ans[i][j]=(ans[i][j]+M1[i][k]*M2[k][j])%mod
    return ans
def pow_mat(M,k,n,mod=10**9+7):
    ans=[[0]*n for _ in range(n)]
    for i in range(n):ans[i][i]=1
    while k:
        if k%2:ans=multi_mat(ans,M,n,mod)
        M=multi_mat(M,M,n,mod)
        k//=2
    return ans

def main():
    n,k=map(int,input().split())
    A=[[int(_) for _ in input().split()] for i in range(n)]
    mod=10**9+7
    Ax=pow_mat(A,k,n,mod)
    print(sum(sum(x)%mod for x in Ax)%mod)

if __name__=='__main__':
    main()