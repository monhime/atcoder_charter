import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    print(180*(n-2))

if __name__=='__main__':
    main()