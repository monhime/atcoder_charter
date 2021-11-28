import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    a, b  = map(int,input().split())
    if b == 0:
        print("Gold")
    elif a == 0:
        print("Silver")
    else:
        print("Alloy")

if __name__=='__main__':
    main()