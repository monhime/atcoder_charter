import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,m=map(int,input().split())
    s=[]
    for i in range(m):
        ss=[int(_) for _ in input().split()]
        s.append(ss[1:])
    P=[int(_) for _ in input().split()]
    ans=0
    for j in range(2**n):#2**n通りのj番目を探索
        nn=j #j番目の値を保存
        i=0 #jのi桁目が1なら操作
        Q=[0]*m
        while nn>0:# nnの2進数表記
            if (nn&1)==1:# nnの最下位が1であれば操作
                for x,ss in enumerate(s):
                    if i+1 in ss:
                        Q[x]+=1
            nn>>=1 #nnを1桁ずらす
            i+=1 #操作の対象番号ずらす
        
        for x,q in enumerate(Q):
            if q%2!=P[x]:
                break
        else:
            ans+=1
    print(ans)


if __name__=='__main__':
    main()