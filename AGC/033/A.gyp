import sys
def input(): return sys.stdin.readline().rstrip()
from collections import deque
def main():
    h,w=map(int,input().split())
    B=[[-1]*w for _ in range(h)]
    ans=0
    que=deque()
    for i in range(h):
        s=input()
        for j,ss in enumerate(s):
            if ss=="#":
                que.append((i,j))
                B[i][j]=0
    while que:
        qr,qc=que.popleft()
        for r,c in ((qr+1,qc),(qr-1,qc),(qr,qc+1),(qr,qc-1)):
            if r>=0 and r<=h-1 and c>=0 and c<=w-1 and B[r][c]==-1:
                B[r][c]=B[qr][qc]+1
                que.append((r,c))
    print(max([max(b) for b in B]))

if __name__=='__main__':
    main()