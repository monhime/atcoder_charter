import sys
def input(): return sys.stdin.readline().rstrip()
from itertools import combinations
from collections import Counter
def main():
    n=int(input())
    if n==1:
        print(1)
        sys.exit()
    XY=[tuple(map(int,input().split())) for i in range(n)]
    XY.sort()
    PQ=[]
    for i in range(n-1):
        x1=XY[i]
        for j in range(i+1,n):
            x2=XY[j]
            PQ.append((x2[0]-x1[0],x2[1]-x1[1]))
    print(n-Counter(PQ).most_common(1)[0][1])

if __name__=='__main__':
    main()