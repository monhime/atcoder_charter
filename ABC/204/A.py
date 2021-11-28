import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    x, y = map(int,input().split())
    if x != y:
        print(3 - (x + y))
    else:
        print(x)

if __name__=='__main__':
    main()