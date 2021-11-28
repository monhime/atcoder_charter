import sys
def input(): return sys.stdin.readline().rstrip()

# 単位元とseg_funcを設定する
from fractions import gcd
class seg():
    def __init__(self,init_val):
        self.n=len(init_val)
        self.ide_ele=10**10 #単位元
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
        #eturn max(a,b) #-1か-10**10 (十分小さいもの)
        return min(a,b) #10**10 (十分大きいもの)
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

#min,max,gcd,seki,rsqとか?
def main():
    n=5
    A=[2,4,6,12,3]

    seg_gcd_A=seg(A)#初期化
    print(seg_gcd_A.query(1,4)) #4 #A[1]~A[3]の和
    print(seg_gcd_A.query(1,2)) #5#A[1]~A[3]の和
    print(seg_gcd_A.query(1,3)) #5#A[1]~A[3]の和
    print(seg_gcd_A.query(1,4)) #5#A[1]~A[3]の和
    print(seg_gcd_A.query(3,5)) #5#A[1]~A[3]の和
    seg_gcd_A.update(2,2) #A[3]を5に変更
    print(seg_gcd_A.query(1,4)) #5#A[1]~A[3]の和 

if __name__=='__main__':
    main()