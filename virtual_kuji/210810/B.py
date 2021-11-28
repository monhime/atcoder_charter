import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n = int(input())
    A = list(map(int,input().split()))
    a_mean = 1.0*sum(A)/n
    B = [0] * n
    for i in range(n):
        B[i] = abs(A[i] - a_mean)
    print(B.index(min(B)))


if __name__=='__main__':
    main()