import sys
def input(): return sys.stdin.readline().rstrip()
from collections import deque
def main():
    n=int(input())
    A=list(map(int,input().split()))
    A.sort(reverse=True)
    Large=deque([a for a in A if a>=0])
    Small=deque([a for a in A if a<0])
    if not Large:Large.append(Small.popleft())
    if not Small:Small.append(Large.pop())
    ans=[]
    while len(Small)>=2:
        a,b=Large.pop(),Small.pop()
        ans.append((a,b))
        Large.append(a-b)
    small=Small.pop()
    while len(Large)>=2:
        a=Large.pop()
        ans.append((small,a))
        small-=a
    large=Large.pop()
    ans.append((large,small))
    print(large-small)
    for a,b in ans:
        print(a,b)

if __name__=='__main__':
    main()