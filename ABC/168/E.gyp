import sys
def input(): return sys.stdin.readline().rstrip()
from fractions import Fraction
from collections import Counter
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
    n=int(input())
    az=0
    bz=0
    abz=0
    b_a=[]
    mod=10**9+7
    AB=[tuple(map(int,input().split())) for i in range(n)]
    for a,b in AB:
        if a==0 and b==0:abz+=1
        elif a==0:az+=1
        elif b==0:bz+=1
        else:
            b_a.append(Fraction(b,a))
    b_ac=Counter(b_a)
    b_ack=list(b_ac.keys())
    ans1=0
    print()
    for b_ackey in b_ack:
        num_a=b_ac[b_ackey]
        num_b=b_ac[-b_ackey**(-1)]#自分と仲の悪い魚の数
        print(b_ackey,num_a,num_b)
        ans1+=(pow(2,num_a,mod)+0)*(pow(2,num_b,mod)+0)%mod
    print(list(b_ac.items()))
    ans2=(pow(2,az,mod)-1)*(pow(2,bz,mod)-1)
    print((pow(2,n-abz,mod)-ans2-ans1//2-1)%mod)

if __name__=='__main__':
    main()