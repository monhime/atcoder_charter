import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n, k = map(int,input().split())
    P = sorted(list(map(int,input().split())))
    print(sum(P[:k]))


if __name__=='__main__':
    main()