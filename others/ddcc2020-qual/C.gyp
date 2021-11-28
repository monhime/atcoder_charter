import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    h,w,k=map(int,input().split())
    S=[input() for _ in range(h)]
    ANS=[[0]*w for _ in range(h)]
    cunt=0
    for i,s in enumerate(S):
        for j,ss in enumerate(s):
            if ss=='#':
                cunt+=1
                ANS[i][j]=cunt
            elif j>=1 and ANS[i][j-1]>0:
                ANS[i][j]=ANS[i][j-1]
        if ANS[i][-1]!=0:
            for j in range(w-2,-1,-1):
                if ANS[i][j]==0:
                    ANS[i][j]=ANS[i][j+1]
    for i in range(h-2,-1,-1):
        if ANS[i][0]==0:
            for j,ans in enumerate(ANS[i+1]):
                ANS[i][j]=ans
    for i in range(h):
        if ANS[i][0]==0:
            for j,ans in enumerate(ANS[i-1]):
                ANS[i][j]=ans
    for ans in ANS:
        print(*ans)

if __name__=='__main__':
    main()