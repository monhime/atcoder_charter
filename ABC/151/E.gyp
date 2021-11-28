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
    n,k=map(int,input().split())
    A=list(map(int,input().split()))
    com=mod_comb3()
    A.sort()
    mod=10**9+7
    max_a,min_a=0,0
    for i in range(n):
        max_a=(max_a+A[i]*com.comb(i,k-1))%mod
        min_a=(min_a+A[i]*com.comb(n-i-1,k-1))%mod
    print((max_a-min_a)%mod)

if __name__=='__main__':
    main()