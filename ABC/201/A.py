import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    A = sorted(list(map(int,input().split())))
    if A[2] - A[1] == A[1] - A[0]:
        print("Yes")
    else:
        print("No")

if __name__=='__main__':
    main()