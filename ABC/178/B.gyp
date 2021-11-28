import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    a, b, c, d = map(int,input().split())
    print(max(a*c,a*d,b*c,b*d))

if __name__=='__main__':
    main()