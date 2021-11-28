import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    a, b = map(int,input().split())
    c, d = map(int,input().split())
    print(max(max(a - c, a - d), max(b - c, b - d)))

if __name__=='__main__':
    main()