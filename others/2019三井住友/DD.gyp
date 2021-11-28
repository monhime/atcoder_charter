import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    s=input()
    dp_0=[[False]*1001 for _ in range(n+1)]
    dp_1=[[False]*1001 for _ in range(n+1)]
    dp_2=[[False]*1001 for _ in range(n+1)]
    dp_3=[[False]*1001 for _ in range(n+1)]
    dp_0[0][0]=True
    
    for k in range(1000):
        for i in range(n):
            if dp_0[i][k]==True:
                dp_0[i+1][k]=True
                dp_1[i+1][10*k+int(s[i])]=True
            if dp_1[i][k]==True:
                dp_1[i+1][k]=True
                dp_2[i+1][10*k+int(s[i])]=True
            if dp_2[i][k]==True:
                dp_2[i+1][k]=True
                dp_3[i+1][10*k+int(s[i])]=True
            if dp_3[i][k]==True:
                dp_3[i+1][k]=True            
    ans=0
    for i in range(1000):
        if dp_3[n][i]:
            ans+=1
    print(ans)

if __name__=='__main__':
    main()