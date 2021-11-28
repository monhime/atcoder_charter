import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    x,y=map(int,input().split())
    if x==y or x%y==0:
        print(-1)
        sys.exit()
    else:
        for i in range(2,10*6):
            if x*i % y!=0:
                print(x*i)
                sys.exit()

if __name__=='__main__':
    main()