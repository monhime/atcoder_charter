import sys
def input(): return sys.stdin.readline().rstrip()
class mod_comb3:
    def __init__(self,mod=10**9+7,n_max=1):
        self.mod,self.n_max=mod,n_max
        self.fact,self.inv,self.factinv=[1,1],[0,1],[1,1]
        if 1<n_max:setup_table(n_max)
    def comb(self,n,r):
        if r<0 or n<r:return 0
        if self.n_max<n:self.setup_table(n)
        return self.fact[n]*(self.factinv[r]*self.factinv[n-r]%self.mod)%self.mod
    def setup_table(self,t):
        for i in range(self.n_max+1,t+1):
            self.fact.append(self.fact[-1]*i%self.mod)
            self.inv.append(-self.inv[self.mod%i]*(self.mod//i)%self.mod)
            self.factinv.append(self.factinv[-1]*self.inv[-1]%self.mod)
        self.n_max=t

def main():
    s = int(input())
    mod = 10**9+7
    mod_c = mod_comb3()
    ans = 0
    for k in range(1,s//3+1):
        ans = (ans + mod_c.comb(s-2*k-1,k-1))%mod
    print(ans)


if __name__=='__main__':
    main()