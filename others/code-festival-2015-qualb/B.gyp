import sys
def input(): return sys.stdin.readline().rstrip()
from collections import Counter
def main():
    n,m=map(int,input().split())
    A=[int(_) for _ in input().split()]
    ac=Counter(A)
    acm=ac.most_common(1)[0]
    if acm[1]>n//2:
        print(acm[0])
    else:
        print('?')

if __name__=='__main__':
    main()