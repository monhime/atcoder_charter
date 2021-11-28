import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    l,x,y,s,d=map(int,input().split())
    if d<=s:
        if x>=y:
            print((l-s+d)/(x+y))
        else:
            print(min((l-s+d)/(x+y),(s-d)/(y-x)))
    else:
        if x>=y:
            print((d-s)/(x+y))
        else:
            print(min((d-s)/(x+y),(s+l-d)/(y-x)))        
if __name__=='__main__':
    main()