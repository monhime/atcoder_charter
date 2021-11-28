import sys
def input(): return sys.stdin.readline().rstrip()
def ctoi(c):
    return ord(c)-97
class BIT:
    def __init__(self, n):
        self.unit_sum=0 # to be set
        self.n=n
        self.dat=[0]*(n+1)#[1,n]
    def add(self,a,x): #a(1-)
        i=a
        while i<=self.n:
            self.dat[i]+=x
            i+=i&-i
    def sum(self,a,b=None):
        if b!=None:
            return self.sum(b-1)-self.sum(a-1) #[a,b) a(1-),b(1-)
        res=self.unit_sum
        i=a
        while i>0:
            res+=self.dat[i]
            i-=i&-i
        return res  #Σ[1,a] a(1-)
    def __str__(self):
        self.ans=[]
        for i in range(1,self.n):
            self.ans.append(self.sum(i,i+1))
        return ' '.join(map(str,self.ans))
def main():
    n=int(input())
    S=list(input())
    q=int(input())
    BIT_tree=[]
    for i in range(26):
        obj=BIT(n+1)
        BIT_tree.append(obj)
    for i in range(n):
        BIT_tree[ctoi(S[i])].add(i+1,1)
    for _ in range(q):
        query=input().split()
        if query[0]=="1":
            index,x=int(query[1])-1,query[2]
            BIT_tree[ctoi(S[index])].add(index+1,-1)
            BIT_tree[ctoi(x)].add(index+1,1)
            S[index]=x
        else:
            l,r=int(query[1])-1,int(query[2])-1
            ans=0
            for c in range(26):
                if BIT_tree[c].sum(l+1,r+2):
                    ans+=1
            print(ans)

if __name__=='__main__':
    main()