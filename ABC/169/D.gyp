import sys
def input(): return sys.stdin.readline().rstrip()
class Sieve2: #√nまでの素因数で試し割り 前処理O(√nloglogn+√n/logn)
    def __init__(self,n):
        self.primes=[]
        self.f=[0]*(int(n**0.5)+1) #ふるい（素数ならその値）
        self.f[0]=self.f[1]=-1
        for i in range(2,int(n**0.5)+1): #素数リスト作成
            if self.f[i]: continue
            self.primes.append(i)
            self.f[i]=i
            for j in range(i*i,int(n**0.5)+1,i):
                if not self.f[j]:
                    self.f[j]=i  #最小の素因数を代入
    def prime_fact(self,x): #素因数分解 {2:p,3:q,5:r,...}
        fact_dict=dict()
        for p in self.primes:
            if p*p>x:break
            while x%p==0:
                x//=p
                fact_dict[p]=fact_dict.get(p,0)+1
        if x>1:fact_dict[x]=fact_dict.get(x,0)+1
        return fact_dict

def main():
    n = int(input())
    Sieve = Sieve2(n)
    prime_dict = Sieve.prime_fact(n)
    ans = 0
    for fact in prime_dict.values():
        f = fact
        x = 1
        while f > 0:
            if f >= x:
                ans += 1
            f -= x
            x += 1
    print(ans)


if __name__=='__main__':
    main()