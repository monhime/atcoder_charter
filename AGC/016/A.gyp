import sys
def input(): return sys.stdin.readline().rstrip()
from collections import Counter
from operator import itemgetter
def main():
    s=input()
    len_s=len(s)
    sc=list(Counter(s).items())
    sc.sort(key=itemgetter(1),reverse=True)
    if sc[0][1]==1:
        print(len_s//2)
        sys.exit()
    ans=100
    for scc in sc:
        dp=[[False]*len_s for _ in range(len_s)]
        for i,ss in enumerate(s):
            if ss==scc[0]:
                dp[0][i]=True
        dp[1][-1]=True
        for sosa in range(len_s):
            if all(dp[sosa]):
                ans=min(ans,sosa)
                break
            for i in range(len_s-1,-1,-1):
                if dp[sosa][i]==True:
                    dp[sosa+1][i]=True
                    if i>0:dp[sosa+1][i-1]=True
    print(ans)

if __name__=='__main__':
    main()