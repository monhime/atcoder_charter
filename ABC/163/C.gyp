import sys
def input(): return sys.stdin.readline().rstrip()
from collections import Counter
def main():
    n=int(input())
    A=[int(_) for _ in input().split()]
    AC=Counter(A)
    for i in range(n):
        print(AC[i+1])

if __name__=='__main__':
    main()