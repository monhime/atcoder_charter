import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    A=[int(_) for _ in input().split()]
    A.sort()
    A_cum=[0]*n
    A_cum[0]=A[0]
    for i in range(1,n):
        A_cum[i]=A_cum[i-1]+A[i]
    for i in range(n-2,-1,-1):
        if 2*A_cum[i]<A[i+1]:
            print(n-1-i)
            break
    else:
        print(n)


if __name__=='__main__':
    main()