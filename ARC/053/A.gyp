import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    h,w=map(int,input().split())
    print((h-1)*w+h*(w-1))


if __name__=='__main__':
    main()