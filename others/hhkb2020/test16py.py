import sys
def input(): return sys.stdin.readline().rstrip()
class seg_lazy():
    def __init__(self, init_val):
        self.n = init_val
        self.ex = 2**31-1 #単位元
        self.num_r = (self.n - 1).bit_length() #n以上の最小の2のべき乗のlog2
        self.num = 2**self.num_r #n以上の最小の2のべき乗
        self.data = [self.ex]*(2*self.num) #i+1番目の頂点の情報
        self.lazy = [None]*(2*self.num) #子に対して遅延させている値（自分は更新済み）

    def fx(self,a,b):
        #return a+b #0
        #return a*b #1
        #return gcd(a,b) #0
        #eturn max(a,b) #0か-1か-10**10 (十分小さいもの，計算に使う場合0)
        return min(a,b) #2**31-1(十分大きいもの)

    #伝搬対象の区間を求める
    #区間Iに含まれる(最小個の)区間を含む区間の列挙
    def gindex(self, l, r):
        self.L = (l + self.num) >> 1 #木の番号にして親へ
        self.R = (r + self.num) >> 1
        self.lc = 0 if l & 1 else (self.L & -self.L).bit_length()#i番目以降記録
        self.rc = 0 if r & 1 else (self.R & -self.R).bit_length()
        for i in range(self.num_r):
            if self.rc <= i:
                yield self.R
            if self.L < self.R and self.lc <= i:
                yield self.L
            self.L >>= 1 #親へ
            self.R >>= 1
    #遅延伝搬処理
    def propagates(self, *ids):
        for i in reversed(ids):
            self.v = self.lazy[i-1]
            if self.v is None:
                continue
            #2つの子のdataとlazyに伝搬
            self.lazy[2*i-1] = self.data[2*i-1] = self.lazy[2*i] = self.data[2*i] = self.v
            self.lazy[i-1] = None

    #[l,r)をxに更新（上書き）
    def update(self, l, r, x):  #l,r: 0-index
        *ids, = self.gindex(l, r)
        self.propagates(*ids) #更新する区間が含まれる全ての区間で遅延させている値lazyをトップダウンに伝搬
        self.L = self.num + l #木の番号へ
        self.R = self.num + r
        while self.L < self.R: #区間Iに含まれる(最小個の)区間の値を全て更新。
            if self.R & 1: #Rが右の子なら（左の子なら親が対象
                self.R -= 1 #その左の頂点を考えて（Rの値は含まない
                self.lazy[self.R-1] = self.data[self.R-1] = x
            if self.L & 1: #Lが右の子なら（左の子なら親が対象
                self.lazy[self.L-1] = self.data[self.L-1] = x
                self.L += 1 #1つ右へ。親は右隣の親になる
            self.L >>= 1 #親へ
            self.R >>= 1 #親へ
        for i in ids: #更新する区間を含む全ての区間の値valueをボトムアップに更新
            self.data[i-1] = self.fx(self.data[2*i-1], self.data[2*i])

    #[l,r)内の最小値を求める
    def query(self, l, r):
        self.propagates(*self.gindex(l, r))
        self.L = self.num + l
        self.R = self.num + r
        self.s = self.ex
        while self.L < self.R:
            if self.R & 1:
                self.R -= 1
                self.s = self.fx(self.s, self.data[self.R-1])
            if self.L & 1:
                self.s = self.fx(self.s, self.data[self.L-1])
                self.L += 1
            self.L >>= 1
            self.R >>= 1
        return self.s

def main():
    

if __name__=='__main__':
    main()