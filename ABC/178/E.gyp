import sys
def input(): return sys.stdin.readline().rstrip()
from operator import itemgetter
def main():
    n = int(input())
    XY = [tuple(map(int,input().split())) for i in range(n)]
    XY.sort()
    ans = 0
    SXY = [[0,0,0] for i in range(n)]
    for i in range(n):
        SXY[i][0] = XY[i][0] + XY[i][1] 
        SXY[i][1] = XY[i][0]
        SXY[i][2] = XY[i][1]
    SXY.sort()
    ans = abs(SXY[0][1]-SXY[-1][1])+abs(SXY[0][2]-SXY[-1][2]) 
    SXY = [[0,0,0] for i in range(n)]
    for i in range(n):
        SXY[i][0] = XY[i][1] - XY[i][0] 
        SXY[i][1] = XY[i][0]
        SXY[i][2] = XY[i][1]
    SXY.sort()
    ans = max(ans,abs(SXY[0][1]-SXY[-1][1])+abs(SXY[0][2]-SXY[-1][2])) 
    print(ans)

if __name__=='__main__':
    main()