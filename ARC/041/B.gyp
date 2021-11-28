import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,m=map(int,input().split())
    B=[[0]*m for _ in range(n)]
    for i in range(n):
        s=input()
        for j,ss in enumerate(s):
            if ss!='0':
                B[i][j]=int(ss)
    A=[[0]*m for _ in range(n)]
    for y in range(1,n-1):
        for x in range(1,m-1):
            k=min(B[y+1][x],B[y-1][x],B[y][x+1],B[y][x-1])
            B[y+1][x]-=k
            B[y-1][x]-=k
            B[y][x+1]-=k
            B[y][x-1]-=k
            A[y][x]=k
    for i in range(n):
        print(''.join(map(str,A[i])))

if __name__=='__main__':
    main()