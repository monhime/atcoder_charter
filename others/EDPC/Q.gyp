import sys
def input(): return sys.stdin.readline().rstrip()
# 単位元とseg_funcを設定する
from fractions import gcd
class seg():
    def __init__(self,init_val):
        self.n=len(init_val)
        self.ide_ele=0 #単位元
        self.num=2**(self.n-1).bit_length() #n以上の最小の2のべき乗
        self.seg=[self.ide_ele]*2*self.num
        for i in range(self.n):
            self.seg[i+self.num-1]=init_val[i]
        for i in range(self.num-2,-1,-1):
            self.seg[i]=self.seg_func(self.seg[2*i+1],self.seg[2*i+2])
    def seg_func(self,a,b):
        #return a+b #0
        #return a*b #1
        #return gcd(a,b) #0
        return max(a,b) #-1か-10**10 (十分小さいもの)
        #return min(a,b) #10**10 (十分大きいもの)
    def update(self,k,x):
        k+=self.num-1
        self.seg[k]=x
        while k:
            k=(k-1)//2
            self.seg[k]=self.seg_func(self.seg[k*2+1],self.seg[k*2+2])
    def query(self,p,q): #O(logN)
        if q<=p:return self.ide_ele
        p+=self.num-1
        q+=self.num-2
        self.res=self.ide_ele
        while q-p>1:
            if p&1==0:
                self.res=self.seg_func(self.res,self.seg[p])
            if q&1==1:
                self.res=self.seg_func(self.res,self.seg[q])
                q-=1
            p=p//2
            q=(q-1)//2
        if p==q:self.res=self.seg_func(self.res,self.seg[p])
        else:self.res=self.seg_func(self.seg_func(self.res,self.seg[p]),self.seg[q])
        return self.res

def main():
    n=int(input())
    H=list(map(int,input().split()))
    A=list(map(int,input().split()))
    dp=[0]*(n+1) #最後の高さがjの並べ方のうち最大の美しさ
    seg_dp=seg(dp)
    for i in range(n):
        temp=seg_dp.query(1,H[i])
        seg_dp.update(H[i],temp+A[i])
    print(seg_dp.query(1,n+1))

if __name__=='__main__':
    main()