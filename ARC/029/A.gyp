import sys
def input(): return sys.stdin.readline().rstrip()
from itertools import product
def main():
    n=int(input())
    T=[0]*n
    for i in range(n):
        T[i]=int(input())
    sum_T=sum(T)
    ans=sum_T
    a=list(product([1,0],repeat=n))
    for aa in a:
        sum_T1=0
        for i,x in enumerate(aa):
            sum_T1+=T[i]*x
        ans=min(ans,max(sum_T1,sum_T-sum_T1))
    print(ans)

if __name__=='__main__':
    main()