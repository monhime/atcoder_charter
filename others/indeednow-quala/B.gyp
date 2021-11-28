import sys
def input(): return sys.stdin.readline().rstrip()
from collections import Counter
def main():
    n=int(input())
    ss="indeednow"
    SS_c=Counter(ss)
    for i in range(n):
        s=input()
        sc=Counter(s)
        if SS_c==sc:
            print("YES")
        else:
            print("NO")

if __name__=='__main__':
    main()