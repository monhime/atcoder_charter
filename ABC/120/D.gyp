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
def main():
    n,m=map(int,input().split())
    AB=[tuple(map(int,input().split())) for i in range(m)]
    ANS=[0]*(m+1)
    ANS[0]=n*(n-1)//2
    uf=UnionFind(n)
    i=0
    for a,b in AB[::-1]:
        a-=1
        b-=1
        if uf.same(a,b):
            ANS[i+1]=ANS[i]
        else:
            na=uf.size(a)
            nb=uf.size(b)
            ANS[i+1]=ANS[i]-na*nb
            uf.unite(a,b)
        i+=1
    for i in range(m):
        print(ANS[-2-i])


if __name__=='__main__':
    main()