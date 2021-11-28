import sys
def input(): return sys.stdin.readline().rstrip()
from collections import Counter
def main():
    n = int(input())
    A = []
    B = []
    for i  in range(n):
        a, b = map(int,input().split())
        A.append(a)
        B.append(b)

    A_c = Counter(A)
    ans = len(A_c.keys())
    added_list = []
    for i in range(n):
        if A_c[B[i]] == 0 and not (B[i] in added_list):
            ans += 1
            added_list.append(B[i])
            A_c[B[i]] -= 1
    print(ans)


if __name__=='__main__':
    main()