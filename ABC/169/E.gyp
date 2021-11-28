import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    A,B=[0]*n,[0]*n
    for i in range(n):
        A[i],B[i]=map(int,input().split())
    A.sort()
    B.sort()
    if n%2==1:
        print(B[n//2]-A[n//2]+1)
    else:
        print(int(((B[n//2-1]+B[n//2])/2-(A[n//2-1]+A[n//2])/2)*2)+1)

if __name__=='__main__':
    main()