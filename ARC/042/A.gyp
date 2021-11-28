import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,m=map(int,input().split())
    A=[[x,x] for x in range(n)]
    for i in range(m):
        nn=int(input())-1
        A[nn][0]=-i-1
    A.sort()
    for i in range(n):
        print(A[i][1]+1)

if __name__=='__main__':
    main()