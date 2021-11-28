import sys
def input(): return sys.stdin.readline().rstrip()
from itertools import product
def main():
    n=int(input())
    XY=[[] for _ in range(n)]
    for i in range(n):
        a=int(input())
        for j in range(a):
            x,y=map(int,input().split())
            XY[i].append((x-1,y))
    tf=list(product([1,0],repeat=n)) #i人目の正直か嘘か
    ans=0
    for tfx in tf:
        for i,x in enumerate(tfx):
            if x==1: #i番目が正直人なら
                for xxy in XY[i]:#i番目の証言を
                    if tfx[xxy[0]]!=xxy[1]:
                        break
                else:
                    continue
                break
        else:
            ans=max(ans,sum(1 if a==1 else 0 for a in tfx))
    print(ans)


        
if __name__=='__main__':
    main()