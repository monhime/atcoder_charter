import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    print(n*(n-1)//2)

if __name__=='__main__':
    main()