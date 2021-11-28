import sys, math, copy
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
# sys.setrecursionlimit(1000000)
def input(): return sys.stdin.readline().rstrip()
from fractions import gcd
# PyPyで出せ
#Reference: https://juppy.hatenablog.com/entry/2019/11/13/%E6%9C%80%E5%A4%A7%E3%83%BB%E6%9C%80%E5%B0%8F%E3%82%BB%E3%82%B0%E6%9C%A8_%E3%82%B3%E3%83%94%E3%83%9A%E7%94%A8_Python
class seg(): 
    def __init__(self,init_val):
        self.n = len(init_val)
        self.ex = 0#単位元
        self.num = 2**(self.n - 1).bit_length() #n以上の最小の2のべき乗
        self.seg = [self.ex]*2*self.num
        for i in range(self.n):
            self.seg[i+self.num-1] = init_val[i]
        for i in range(self.num-2,-1,-1):
            self.seg[i] = self.fx(self.seg[2*i+1],self.seg[2*i+2])
    def fx(self, a, b):
        return a + b #0
        #return a * b #1
        #return gcd(a, b) #0
        #return max(a, b) #0か-1か-10**10 (十分小さいもの，計算に使う場合0)
        #return min(a, b) #10**10 (十分大きいもの)
        #return a ^ b #0
    def update(self, k, x): 
        k += self.num - 1
        self.seg[k] += x # or +=x
        while k:
            k = (k - 1)//2
            self.seg[k] = self.fx(self.seg[k*2 + 1],self.seg[k*2 + 2])
    def query(self, p, q): #O(logN) # [p, q)の和
        if q <=p:return self.ex
        p += self.num - 1
        q += self.num - 2
        self.res = self.ex
        while q - p > 1:
            if p&1 == 0:
                self.res = self.fx(self.res, self.seg[p])
            if q&1 == 1:
                self.res = self.fx(self.res, self.seg[q])
                q -= 1
            p = p//2
            q = (q - 1)//2
        if p == q:self.res=self.fx(self.res,self.seg[p])
        else:self.res = self.fx(self.fx(self.res,self.seg[p]), self.seg[q])
        return self.res

def main():
    mod = 10**9 + 7
    inf = 10**10
    
    n, q = map(int,input().split())
    A = list(map(int,input().split()))
    SEG = seg(A)
    for _ in range(q):
        s, a, b = map(int,input().split())
        if s == 0:
            SEG.update(a, b)
        else:
            print(SEG.query(a, b))
    
if __name__=='__main__':
    main()