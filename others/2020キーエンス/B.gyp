import sys
def input(): return sys.stdin.readline().rstrip()
from operator import itemgetter
def main():
    n=int(input())
    ST=[]
    for i in range(n):
        x,l=map(int,input().split())
        ST.append((x-l,x+l))
    ST.sort(key=itemgetter(1))
    ans=0
    for i,st in enumerate(ST):
        if i==0:
            ans+=1
            max_t=st[1]
        if max_t<=st[0]:
            ans+=1
            max_t=st[1]
    print(ans)




if __name__=='__main__':
    main()