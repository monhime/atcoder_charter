import sys
def input(): return sys.stdin.readline().rstrip()
from bisect import bisect_left,bisect
def main():
    n=int(input())
    S=list(input())
    q=int(input())
    set_s={chr(ord('a')+i):[] for i in range(26)}
    for i,s in enumerate(S):
        set_s[s].append(i)
    for _ in range(q):
        query=input().split()
        if query[0]=="1":
            i,c=int(query[1])-1,query[2]
            if S[i]==c:continue
            set_s[S[i]].remove(i)
            set_s[c].insert(bisect_left(set_s[c],i),i)
            S[i]=c
        else:
            l,r=int(query[1])-1,int(query[2])-1
            ans=0
            for i in range(26):
                ss=chr(ord('a')+i)
                if bisect(set_s[ss],r)>bisect_left(set_s[ss],l):
                    ans+=1
            print(ans)


if __name__=='__main__':
    main()