import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n = int(input())
    A = list(map(int,input().split()))
    A.sort()
    A_left = 0
    for i in range(1, n):
        A_left += (n - i)* A[i - 1]
    A_right = 0
    for i in range(1, n + 1):
        A_right += A[i - 1]*(i - 1)
    print(A_right - A_left)

if __name__=='__main__':
    main()