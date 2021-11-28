import sys
from collections import Counter
def input(): return sys.stdin.readline().rstrip()
def main():
    n,k,q=map(int,input().split())
    A=[int(input())for _ in range(q)]
    A_C=Counter(A)
    for i in range(n):
        if k-q+A_C[i+1]>0:print("Yes")
        else:print("No")

if __name__=='__main__':
    main()