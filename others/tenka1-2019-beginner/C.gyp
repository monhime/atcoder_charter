import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    S=input()
    C=[[0,0] for _ in range(n)] #i以下の#の数，i以上の.の数
    cunt=0
    for i,s in enumerate(S):
        if s=='#':
            cunt+=1
        C[i][0]=cunt
    cunt=0
    for i in range(n-1,-1,-1):
        if S[i]=='.':
            cunt+=1
        C[i][1]=cunt  
    ans=C[0][1]
    for i in range(n-1):#.#をとる位置
        ans=min(ans,C[i][0]+C[i+1][1])
    ans=min(ans,C[n-1][0])
    print(ans)

if __name__=='__main__':
    main()