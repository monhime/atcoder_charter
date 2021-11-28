import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,k=map(int,input().split())
    A=list(map(int,input().split()))
    F=list(map(int,input().split()))
    F.sort(reverse=True)
    A.sort()
    right=10**12
    left=-1
    while right-left>1:#区間(left,right]に解Xがある
        x=(right+left)//2
        k_sum=0
        for i in range(n):
            k_sum+=max(0,A[i]-x//F[i])
            if k_sum>k:
                left=x
                break
        else:
            right=x
    print(right)
    

if __name__=='__main__':
    main()