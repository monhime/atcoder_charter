import sys
def input(): return sys.stdin.readline().rstrip()
from itertools import accumulate
def main():
    n, m, k = map(int,input().split())
    A = [0] + list(map(int,input().split()))
    B = [0] + list(map(int,input().split()))
    A = list(accumulate(A))
    B = list(accumulate(B))
    ans = 0
    j = m
    for i in range(n + 1):
        if A[i] > k:
            break
        while A[i] + B[j] > k:
            j -= 1
        ans = max(ans, i + j)
    print(ans)


if __name__=='__main__':
    main()