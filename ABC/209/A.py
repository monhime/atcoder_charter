import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    a, b = map(int,input().split())
    if a <= b:
        print(b - a + 1)
    else:
        print(0)
if __name__=='__main__':
    main()