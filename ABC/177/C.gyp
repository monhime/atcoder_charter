import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n = int(input())
    A = list(map(int,input().split()))
    mod = 10**9 + 7
    sum_A = sum(A)%mod
    ans = 0
    for a in A:
        sum_A -= a
        ans += a*sum_A%mod
    print(ans%mod)

if __name__=='__main__':
    main()