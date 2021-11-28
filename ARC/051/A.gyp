import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    x1,y1,r=map(int,input().split())
    x2,y2,x3,y3=map(int,input().split())
    if x2<=x1-r and x1+r<=x3 and y2<=y1-r and y1+r<=y3:
        print("NO")
        print("YES")
    elif (x3-x1)**2+(y3-y1)**2<=r**2 and (x3-x1)**2+(y2-y1)**2<=r**2 and (x2-x1)**2+(y3-y1)**2<=r**2 and (x2-x1)**2+(y2-y1)**2<=r**2:
        print("YES")
        print("NO")
    else:
        print("YES")
        print("YES")

if __name__=='__main__':
    main()