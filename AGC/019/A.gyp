import sys
def input(): return sys.stdin.readline().rstrip()
from operator import itemgetter
def main():
    q,h,s,d=map(int,input().split())
    n=int(input())
    weight=[(0.25,q,q/0.25),(0.5,h,h/0.5),(1,s,s),(2,d,d/2)]
    weight.sort(key=itemgetter(2))
    cost=0
    for w in weight:
        kosu=n//w[0]
        cost+=int(w[1]*kosu)
        n-=w[0]*kosu
    print(cost)
if __name__=='__main__':
    main()