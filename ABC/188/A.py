import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    x, y = map(int,input().split())
    if x < y:
        x, y = y, x
    if x < y + 3:
        print('Yes')
    else:
        print('No')

if __name__=='__main__':
    main()