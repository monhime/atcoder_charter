import sys
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
import math
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
    inf = 10**9 + 7

    n, m, q = map(int,input().split())
    ABCD = [[int(_) for _ in input().split()] for i in range(q)]
    ABCD.sort(key = itemgetter(3), reverse = True)
    UF = UnionFind(n)
    ans = 0
    graph = [[] for _ in range(n)]
    kyori = [[inf]*n for _ in range(n)] 
    for i in range(n):
        kyori[i][i] = 0
    for a, b, c, d in ABCD:
        a -= 1
        b -= 1
        if not UF.same(a, b):
            graph[a].append(b)
            graph[b].append(a)
            kyori[a][b] = c
            kyori[b][a] = -c
            UF.unite(a, b)
            ans += d
            print(graph)
            # 距離テーブル更新
            for s in range(n):
                queue = deque([s])
                visited = [False] * n
                visited[s] = True
                while queue:
                    node = queue.popleft()
                    for xnode in graph[node]:
                        if visited[xnode]:
                            continue
                        visited[xnode] = True
                        queue.append(xnode)
                        kyori[s][xnode] = kyori[s][node] + kyori[node][xnode]
        else:
            # 矛盾ないか？
            if kyori[a][b] == c:
                ans += d
            else:
                continue
    print(kyori)
    print(ans)    

if __name__=='__main__':
    main()