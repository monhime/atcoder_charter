import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    A = sorted(list(map(int,input().split())))
    print(A[1] + A[2])

if __name__=='__main__':
    main()