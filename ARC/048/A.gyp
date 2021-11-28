import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    a,b=map(int,input().split())
    if a*b<0:
        print(b-a-1)
    else:print(b-a)

if __name__=='__main__':
    main()