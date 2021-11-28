import sys
def input(): return sys.stdin.readline().rstrip()
class UnionFind():
    def __init__(self, n):
        self.n=n
        self.parents=[-1]*n # 親(uf.find()で経路圧縮して根)の番号。根の場合は-(そのグループの要素数)
        self.member_color=[[0,0]for _ in range(n)] #.の数，#の数
        for i in range(n):
            if S[i//w][i%w]=="#": 
                self.member_color[i][1]=1
            else:
                self.member_color[i][0]=1
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
        self.member_color[x][0]+=self.member_color[y][0]
        self.member_color[x][1]+=self.member_color[y][1] 
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
    global w,S
    h,w=map(int,input().split())
    S=[input() for _ in range(h)]
    uf=UnionFind(h*w)
    for i in range(h):
        for j in range(w):
            ss=S[i][j]
            for row,col in ((1,0),(-1,0),(0,1),(0,-1)):
                if i+row>=0 and i+row<h and j+col>=0 and j+col<w and ss!=S[i+row][j+col]:
                    uf.unite((i+row)*w+j+col,i*w+j) 
    ans=0
    for r in uf.roots():
        ans+=uf.member_color[r][0]*uf.member_color[r][1]
    print(ans)
if __name__=='__main__':
    main()