import sys
def input(): return sys.stdin.readline().rstrip()
from heapq import heappop,heappush

def main():
    n = int(input())
    A = list(map(int,input().split()))
    A_h = heapq.heapify(A)
    while()

    min_diff = 10**9 + 1
    for i in range(n - 1):
        if A[i + 1] - A[i] > 0:
            min_diff = min(min_diff, A[i + 1] - A[i])
    print(min(min(A), min_diff))


if __name__=='__main__':
    main()