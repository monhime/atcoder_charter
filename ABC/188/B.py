import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n = int(input())
    A = list(map(int,input().split()))
    B = list(map(int,input().split()))
    ans = 0
    for i in range(n):
        ans += A[i] * B[i]
    if ans == 0:
        print("Yes")
    else:
        print("No")

if __name__=='__main__':
    main()