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
def main():
    n, m = map(int,input().split())
    uf = UnionFind(n)
    for i in range(m):
        a, b = map(int,input().split())
        a -= 1
        b -= 1
        uf.unite(a, b)
    uf_lis = uf.parents
    ans = 0
    for p in uf_lis:
        if p < 0:
            ans = max(ans, -p)
    print(ans)


if __name__=='__main__':
    main()