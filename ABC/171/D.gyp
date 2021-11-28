import sys
def input(): return sys.stdin.readline().rstrip()
from collections import Counter
def main():
    n = int(input())
    A = list(map(int,input().split()))
    Q = int(input())
    S = sum(A)
    cunt_A = Counter(A)
    for q in range(Q):
        b, c = map(int,input().split())
        S += (c-b)*cunt_A[b]
        cunt_A[c] += cunt_A[b]
        cunt_A[b] = 0
        print(S)

if __name__=='__main__':
    main()