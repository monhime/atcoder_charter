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
        
def main():
    n,m,k=map(int,input().split())
    AB=[tuple(map(int,input().split())) for i in range(m)]
    CD=[tuple(map(int,input().split())) for i in range(k)]
    un=UnionFind(n)
    friend=[[] for _ in range(n)]
    for a,b in AB:
        un.unite(a-1,b-1)
        friend[a-1].append(b-1)
        friend[b-1].append(a-1)
    blockc=[0]*n
    for c,d in CD:
        if un.same(c-1,d-1):
            blockc[c-1]+=1
            blockc[d-1]+=1
    for i in range(n):
        print(un.size(i)-1-blockc[i]-len(friend[i]))
 
if __name__=='__main__':
    main()