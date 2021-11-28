import sys
def input(): return sys.stdin.readline().rstrip()
from collections import Counter
def main():
    n=int(input())
    D=[int(_) for _ in input().split()]
    D_c=Counter(D)
    M=int(input())
    T=[int(_) for _ in input().split()]
    T_c=Counter(T)
    for t in T_c.items():
        if D_c[t[0]]<t[1]:
            print("NO")
            break
    else:
        print("YES")

if __name__=='__main__':
    main()