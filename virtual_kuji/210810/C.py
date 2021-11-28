import sys
def input(): return sys.stdin.readline().rstrip()
from functools import reduce
def mod_comb4(n,r,mod=10**9+7):
    if r==1:return n
    elif r==0:return 1
    else:
        num=reduce(lambda x,y:x*y%mod,range(n,n-r,-1))
        den=reduce(lambda x,y:x*y%mod,range(1,r+1))
        return num*pow(den,mod-2,mod)%mod

def main():
    n, m = map(int,input().split())
    A = [int(input())for _ in range(m)]

    mod = 1000000007
    
    pre_a = 0
    if m == 0:
        ans = 0
        _n = n
        for k in range(_n//2 + 1):
            def modinv(x):
                return pow(x, mod-2, mod)

            modinv_table = [-1] * (k + 1)
            for i in range(1, k + 1):
                modinv_table[i] = modinv(i)

            def binomial_coefficients(n, k):
                ans = 1
                for i in range(k):
                    ans *= n-i
                    ans *= modinv_table[i + 1]
                    ans %= mod
                return ans
            ans = (ans + binomial_coefficients(_n - k, k)) % mod
        print(ans%mod)
        exit()
    ans = 1
    for a in A:
        ans_each = 0
        _n = a - pre_a - 1 # 次の段数
        if a == pre_a:
            print(0)
            exit()
        for k in range(_n//2 + 1):
            ans_each = (ans_each + mod_comb4(_n - k, k)) % mod
        pre_a = a + 1
        ans *= ans_each
    ans_each = 0
    _n = n - pre_a  # 次の段数
    for k in range(_n//2 + 1):
        ans_each = (ans_each + mod_comb4(_n - k, k)) % mod
    ans *= ans_each
    print(ans%mod)


if __name__=='__main__':
    main()