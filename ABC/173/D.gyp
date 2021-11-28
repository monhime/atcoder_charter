import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n = int(input())
    A = list(map(int,input().split()))
    A.sort(reverse = True)
    ans = A[0]
    for i in range(n-2):
        ans += A[i//2 + 1]
    print(ans)

if __name__=='__main__':
    main()