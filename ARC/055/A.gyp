import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    print(10**n+7)

if __name__=='__main__':
    main()