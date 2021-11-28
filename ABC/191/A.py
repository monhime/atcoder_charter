import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    v, t, s, d = map(int,input().split())
    if v*t > d or v*s < d:
        print("Yes")
    else:
        print("No")

if __name__=='__main__':
    main()