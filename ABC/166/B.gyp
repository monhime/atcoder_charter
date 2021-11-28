import sys
def input(): return sys.stdin.readline().rstrip()
from collections import Counter
def main():
    n,k=map(int,input().split())
    A=[0]*n
    for i in range(k):
        _=int(input())
        a=[int(_) for _ in input().split()]
        for aa in a:
            A[aa-1]+=1
    ac=Counter(A)
    print(ac[0])

if __name__=='__main__':
    main()