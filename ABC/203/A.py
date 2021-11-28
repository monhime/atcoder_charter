import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    a, b, c = sorted(list(map(int,input().split())))
    if a == b:
        print(c)
    elif b == c:
        print(a)
    else:
        print(0)

if __name__=='__main__':
    main()