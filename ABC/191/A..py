import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    v, t, s, d = map(int,input().split())
    if v*t < d and v*s > d:
        print("Yes\n")
    else:
        print("No\n")

if __name__=='__main__':
    main()