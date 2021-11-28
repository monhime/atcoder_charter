import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    h,w=map(int,input().split())
    if h==1 or w==1:
        print(1)
        sys.exit()
    if h*w%2==0:print(h*w//2)
    else:print((h*w+1)//2)

if __name__=='__main__':
    main()