import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    d, t, s = map(int,input().split())
    if d>s*t:
        print("No")
    else:
        print("Yes")

if __name__=='__main__':
    main()