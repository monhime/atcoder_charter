import sys, math, copy
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
# sys.setrecursionlimit(1000000)
def input(): return sys.stdin.readline().rstrip()
class UnionFind(): #https://note.nkmk.me/python-union-find/
    def __init__(self, n):
        self.n=n
        self.parents=[-1]*n # 親(uf.find()で経路圧縮して根)の番号。根の場合は-(そのグループの要素数)
    def find(self,x):
        #グループの根を返す
        if self.parents[x]<0:return x
        else:
            self.parents[x]=self.find(self.parents[x])
            return self.parents[x]
    def unite(self,x,y):
        #要素x,yのグループを併合
        x,y=self.find(x),self.find(y)
        if x==y:return
        if self.parents[x]>self.parents[y]:#要素数の大きい方をxに
            x,y=y,x
        self.parents[x]+=self.parents[y]
        self.parents[y]=x #要素数が大きい方に併合
    def size(self,x):
        #xが属するグループの要素数
        return -self.parents[self.find(x)]
    def same(self,x,y):
        #xとyが同じグループ？
        return self.find(x)==self.find(y)
    def members(self,x):
        #xと同じグループに属する要素のリスト
        root=self.find(x)
        return [i for i in range(self.n) if self.find(i)==root]
    def roots(self):
        #全ての根の要素のリスト
        return [i for i, x in enumerate(self.parents) if x<0]
    def group_count(self):
        #グループの数
        return len(self.roots())
    def all_group_count(self):
        #各ルート要素のグループに含まれる要素数
        return {r: -self.parents[r] for r in self.roots()}
    def all_group_members(self):
        #各ルート要素のグループに含まれる要素のリストの辞書
        return {r: self.members(r) for r in self.roots()}
    def all_group_members_list(self):
        #各ルート要素のグループに含まれる要素のリストのリスト
        #[[0, 2], [1, 3, 4, 5]]
        return list(self.all_group_members().values())
    def __str__(self):
        #各ルート要素のグループに含まれる要素のリストをprint()
        return '\n'.join('{}: {}'.format(r,self.members(r)) for r in self.roots())

def main():
    mod = 10**9 + 7
    inf = 10**10
    
    n = int(input())
    A = list(map(int,input().split()))
    UF = UnionFind(max(A))
    for i in range(n//2):
        if A[i] != A[-1 - i]:
            UF.unite(A[i] - 1, A[-1 - i] - 1)
    uf_dict = UF.all_group_count()
    ans = 0
    for x in uf_dict.values():
        ans +=  x - 1
    print(ans)

if __name__=='__main__':
    main()