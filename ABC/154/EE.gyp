import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    s=input()
    n=len(s)
    K=int(input())
    dp_0=[[0]*(K+1) for _ in range(n+1)]
    dp_1=[[0]*(K+1) for _ in range(n+1)]
    dp_0[0][0]=1 
    for i in range(n):
        for j in range(K+1):
            for k in range(2):
                nd=int(s[i])-0
                for d in range(10): 
                    ni=i+1
                    nj=j
                    if d!=0:nj+=1
                    if nj>K:continue
                    if k==0:
                        if d>nd:continue
                        if d<nd:dp_1[ni][nj]+=dp_0[i][j]
                        else:dp_0[ni][nj]+=dp_0[i][j]
                    else:dp_1[ni][nj]+=dp_1[i][j]
    print(dp_0[n][K]+dp_1[n][K])

if __name__=='__main__':
    main()