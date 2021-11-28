import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    a, b = map(int,input().split())
    if b >= a and b <= 6*a:
        print("Yes")
    else:
        print("No")

if __name__=='__main__':
    main()