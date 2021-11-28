import sys
def input(): return sys.stdin.readline().rstrip()
class UnionFind():
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
        return '\n'.join('{}: {}'.format(r, self.members(r)) for r in self.roots())

class UnionFindLabel(UnionFind):
    def __init__(self, labels):
        assert len(labels)==len(set(labels))
        self.n=len(labels)
        self.parents=[-1]*self.n
        self.d={x: i for i,x in enumerate(labels)}
        self.d_inv={i: x for i,x in enumerate(labels)}
    def find_label(self,x):
        return self.d_inv[super().find(self.d[x])]
    def unite(self,x,y):
        super().unite(self.d[x], self.d[y])
    def size(self,x):
        return super().size(self.d[x])
    def same(self,x,y):
        return super().same(self.d[x],self.d[y])
    def members(self,x):
        root=self.find(self.d[x])
        return [self.d_inv[i] for i in range(self.n) if self.find(i)==root]
    def roots(self):
        return [self.d_inv[i] for i,x in enumerate(self.parents) if x<0]

def main():
    l = ['A', 'B', 'C', 'D', 'E']
    ufl = UnionFindLabel(l)
    print(ufl)
    # A: ['A']
    # B: ['B']
    # C: ['C']
    # D: ['D']
    # E: ['E']
    ufl.unite('A', 'D')
    ufl.unite('D', 'C')
    ufl.unite('E', 'B')
    print(ufl)
    # A: ['A', 'C', 'D']
    # E: ['B', 'E']
    print(ufl.find_label('D'))# A
    print(ufl.size('D'))# 
    print(ufl.same('A', 'D'))# True
    print(ufl.members('D'))# ['A', 'C', 'D']
    print(ufl.roots())# ['A', 'E']
    print(ufl.group_count())# 2
    print(ufl.all_group_members())# {'A': ['A', 'C', 'D'], 'E': ['B', 'E']}

    ufl_n = UnionFindLabel([1, 2, 3, 4, 5])
    print(ufl_n)
    # 1: [1]
    # 2: [2]
    # 3: [3]
    # 4: [4]
    # 5: [5]
    ufl_n.unite(1, 4)
    ufl_n.unite(4, 3)
    ufl_n.unite(5, 2)
    print(ufl_n)
    # 1: [1, 3, 4]
    # 5: [2, 5]

if __name__=='__main__':
    main()