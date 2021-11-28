import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    x,y=map(int,input().split())
    k=int(input())
    if k<=y:
        print(x+k)
    else:
        print(2*y+x-k)

if __name__=='__main__':
    main()