import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n = int(input())
    A = list(map(int,input().split()))
    kabu = 0
    kane = 1000
    for i in range(n-1):
        if A[i+1] > A[i]:
            kabu += kane // A[i]
            kane %= A[i]
        elif A[i+1] < A[i]:
            kane += kabu * A[i]
            kabu = 0
    kane += kabu * A[n-1]
    print(kane)

if __name__=='__main__':
    main()