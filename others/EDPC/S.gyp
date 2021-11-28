import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    k=input()
    len_k=len(k)
    d=int(input())
    mod=10**9+7
    dp_0=[[0]*d for _ in range(len_k+1)]
    dp_1=[[0]*d for _ in range(len_k+1)] 
    dp_0[0][0]=1
    for i in range(len_k):
        ni=int(k[i])
        for j in range(d):
            for dig in range(10):
                dp_1[i+1][(j+dig)%d]=(dp_1[i+1][(j+dig)%d]+dp_1[i][j])%mod
            for dig in range(ni):
                dp_1[i+1][(j+dig)%d]=(dp_1[i+1][(j+dig)%d]+dp_0[i][j])%mod
            dp_0[i+1][(j+ni)%d]=(dp_0[i+1][(j+ni)%d]+dp_0[i][j])%mod
    print((dp_0[len_k][0]+dp_1[len_k][0]-1)%mod)

if __name__=='__main__':
    main()