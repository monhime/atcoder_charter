import sys
def input(): return sys.stdin.readline().rstrip()
from collections import Counter
def main():
    n,m=map(int,input().split())
    AB=[]
    for i in range(m):
        a,b=map(int,input().split())
        AB.append(a)
        AB.append(b)
    abc=list(Counter(AB).values())
    print("YES" if all(x%2==0 for x in abc) else "NO")


if __name__=='__main__':
    main()