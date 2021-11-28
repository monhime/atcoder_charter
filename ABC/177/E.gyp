import sys
def input(): return sys.stdin.readline().rstrip()
class Sieve: #区間[2,n]の値の素因数分解 O(nloglogn+logn)
    def __init__(self,n): #nは計算対象としてありうる最大の値
        self.primes=[]
        self.f=[0]*(n+1) #ふるい（素数ならその値）
        self.f[0]=self.f[1]=-1
        self.f_lis = [0]*(n+1)
        for i in range(2,n+1): #素数リスト作成
            if self.f[i]: continue
            self.primes.append(i)
            self.f[i]=i
            for j in range(i*i,n+1,i):
                if not self.f[j]:
                    self.f[j]=i  #最小の素因数を代入
    def prime_fact(self,A): #素因数分解 {2:p,3:q,5:r,...}
        for x in A:
            while x!=1:
                p=self.f[x]
                x//=p
                if x % p > 0:
                    if self.f_lis[p] > 0: return False
                    self.f_lis[p] += 1
        return True

import math
from functools import reduce
def gcd_all(numbers):#gcd(A)
    return reduce(math.gcd, numbers)

def main():
    n = int(input())
    A = list(map(int,input().split())) 
    Sieve_a = Sieve(max(A)+1)
    if Sieve_a.prime_fact(A):
        print("pairwise coprime")
    elif gcd_all(A) == 1:
        print("setwise coprime")   
    else:
        print("not coprime")

if __name__=='__main__':
    main()