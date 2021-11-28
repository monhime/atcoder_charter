import sys
def input(): return sys.stdin.readline().rstrip()
from operator import itemgetter
def main():
    n=int(input())
    XYH=[tuple(map(int,input().split())) for i in range(n)]
    XYH.sort(key=itemgetter(2),reverse=True)
    for cy in range(101):
        for cx in range(101):
            hc=XYH[0][2]+abs(cx-XYH[0][0])+abs(cy-XYH[0][1])
            for x,y,h in XYH[1:]:
                if h!=max(0,hc-abs(x-cx)-abs(y-cy)):
                    break
            else:
                print(cx,cy,hc)
                sys.exit()

if __name__=='__main__':
    main()