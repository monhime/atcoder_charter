import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,k=map(int,input().split())
    S=input()
    lis=[0]
    for i in range(1,n):
        if S[i-1]!=S[i]:
            lis.append(i)
    lis.append(n)
    len_lis=len(lis)
    ans=[]
    for i in range(len_lis-1):
        if S[lis[i]]=='0':
            ans.append(lis[min(i+2*k,len_lis-1)]-lis[i])
        else:
            ans.append(lis[min(i+2*k+1,len_lis-1)]-lis[i])
    print(max(ans))

if __name__=='__main__':
    main()