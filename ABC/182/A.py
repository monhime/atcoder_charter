import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    a, b = map(int,input().split())
    print((2*a) + 100 - b)

if __name__=='__main__':
    main()