import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n = int(input())
    A = list(map(int,input().split()))
    B = [0] * n
    x = 0
    for a in A:
        x ^= a
    for i in range(n):
        B[i] = x^A[i]
    print(" ".join(map(str,B)))


if __name__=='__main__':
    main()