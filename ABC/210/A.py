import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n, a, x, y = map(int,input().split())
    if n <= a:
        print(x * n)
    else:
        print(x * a + y * (n - a))

if __name__=='__main__':
    main()