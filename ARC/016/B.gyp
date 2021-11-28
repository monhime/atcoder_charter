import sys
def input(): return sys.stdin.readline().rstrip()
from collections import Counter
def main():
    n=int(input())
    maru_flag=[False]*9
    ans=0
    s_pre="........."
    for i in range(n):
        s=input() 
        for i,ss in enumerate(s):
            if 'x'==ss or ('o'==ss and  s_pre[i]!='o') :
                ans+=1
        s_pre=s
    print(ans)

if __name__=='__main__':
    main()