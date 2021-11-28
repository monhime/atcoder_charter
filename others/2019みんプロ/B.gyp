import sys
def input(): return sys.stdin.readline().rstrip()
from collections import Counter
def main():
    N=[]
    for _ in range(3):
        a,b=map(int,input().split())
        N.append(a)
        N.append(b)
    N=Counter(N)
    NN=N.most_common(1)
    if NN[0][1]==3:
        print("NO")
    else:
        print("YES")


if __name__=='__main__':
    main()