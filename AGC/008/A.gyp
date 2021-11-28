import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    x,y=map(int,input().split())
    if x==-y:
        print(1)
    elif x*y>0:
        if x<y:
            print(y-x)
        else:
            print(x-y+2)
    elif x*y<0:
        print(abs(x+y)+1)
    else:
        if x>0:
            print(x+1)
        elif x<0:
            print(-x)
        elif y>0:
            print(y)
        else:
            print(-y+1)

if __name__=='__main__':
    main()