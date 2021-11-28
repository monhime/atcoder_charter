import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    A = list(map(int,input().split()))
    print(min(A))

if __name__=='__main__':
    main()