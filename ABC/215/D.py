import sys, math, copy
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
# sys.setrecursionlimit(1000000)
def input(): return sys.stdin.readline().rstrip()
class Sieve: #区間[2,n]の値の素因数分解 O(nloglogn+logn)
    def __init__(self,n): #nは計算対象としてありうる最大の値
        self.primes=[]
        self.f=[0]*(n+1) #ふるい（素数ならその値）
        self.f[0]=self.f[1]=-1
        self.fact_dict = dict()
        for i in range(2,n+1): #素数リスト作成
            if self.f[i]: continue
            self.primes.append(i)
            self.f[i]=i
            for j in range(i*i,n+1,i):
                if not self.f[j]:
                    self.f[j]=i  #最小の素因数を代入
    def is_prime(self, x):
        return self.f[x]==x
    def prime_fact(self,x): #素因数分解 {2:p,3:q,5:r,...}
        while x!=1:
            p=self.f[x]
            self.fact_dict[p]=self.fact_dict.get(p,0)+1
            x//=self.f[x]
def main():
    mod = 10**9 + 7
    inf = 10**10
    
    n, m = map(int,input().split())
    A = list(map(int,input().split()))

    SIEVE = Sieve(max(max(A), m))
    for a in A:
        SIEVE.prime_fact(a)
    ANS = []
    fact_lis = sorted(SIEVE.fact_dict.keys())
    for i in range(1, m + 1):
        for j in fact_lis:
            if j > m:
                ANS.append(i)
                break
            if i % j  == 0:
                break
        else:
            ANS.append(i)
    print(len(ANS))
    for a in ANS:
        print(a)
    
if __name__=='__main__':
    main()