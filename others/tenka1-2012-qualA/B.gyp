import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    C=input().split()
    print(','.join(C))


if __name__=='__main__':
    main()