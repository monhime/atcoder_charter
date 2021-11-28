import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n, k = map(int,input().split())
    A = list(map(int,input().split()))
    for i in range(k,n):
        if A[i-k] < A[i]:
            print("Yes")
        else:
            print("No")

if __name__=='__main__':
    main()