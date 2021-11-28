import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    x = int(input())
    if x >= 30:
        print("Yes")
    else:
        print("No")

if __name__=='__main__':
    main()