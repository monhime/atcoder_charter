import sys
def input(): return sys.stdin.readline().rstrip()
from fractions import gcd
class BIT:
    def __init__(self, init_val):
        self.ex = 0 #単位元
        self.n = len(init_val)
        self.dat = [self.ex]*(self.n + 1) #[1, n]1indexで管理
        for i in range(1, self.n + 1):
            self.update(i, init_val[i - 1])

    def update(self, a, x): #a(1-index)
        self.i = a
        while self.i <= self.n:
            self.dat[self.i] = self.fx(self.dat[self.i], x)
            self.i += self.i & -self.i #担当する区間の長さ（最下位bit）だけ足すと次に更新すべき区間になる
    def query(self, a, b = None): #[1, a]の和を求める or [a, b)の和を求める
        if b != None:
            #fxがxorのとき
            return self.query(b - 1) ^ self.query(a - 1) 
            #fxがsumのとき
            #return self.query(b - 1) - self.query(a - 1) #[a,b) a(1-),b(1-)
        
        self.res = self.ex
        self.i = a
        while self.i > 0:
            self.res = self.fx(self.res, self.dat[self.i])
            self.i -= self.i & -self.i
        return self.res  #Σ[1,a] a(1-)
    
    def fx(self, a, b):
        #return a + b #0
        #return a * b #1
        #return gcd(a, b) #0
        #return max(a, b) #0か-1か-10**10 (十分小さいもの，計算に使う場合0)
        #return min(a, b) #10**10 (十分大きいもの)
        return a ^ b #0

    def __str__(self):
        self.ans = []
        for i in range(1, self.n):
            self.ans.append(self.fx(i, i+1))
        return ' '.join(map(str,self.ans))

def main():
    n, Q = map(int,input().split())
    A = list(map(int,input().split()))
    bit1 = BIT(A)
    for i in range(Q):
        s = list(map(int,input().split()))
        if s[0] == 1:
            bit1.update(s[1], s[2])
        elif s[0] == 2:
            print(bit1.query(s[1], s[2] + 1))
    

if __name__=='__main__':
    main()
