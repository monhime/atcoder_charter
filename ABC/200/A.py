import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n = int(input())
    print((n - 1)//100 + 1)

if __name__=='__main__':
    main()