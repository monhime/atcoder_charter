import sys
def input(): return sys.stdin.readline().rstrip()
from operator import itemgetter
def main():
    n,m=map(int,input().split())
    A=[int(_) for _ in input().split()]
    A.sort()
    D=[[int(_) for _ in input().split()] for i in range(m)]
    D.sort(key=itemgetter(1),reverse=True)
    len_D=len(D)
    index_d=0
    for i in range(n):
        if D[index_d][0]==0:
            index_d+=1
            if index_d==len_D:
                break
        if A[i]>=D[index_d][1]:
            break
        A[i]=D[index_d][1]
        D[index_d][0]-=1
    print(sum(A))

if __name__=='__main__':
    main()