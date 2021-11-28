import sys
def input(): return sys.stdin.readline().rstrip()
from collections import deque
def main():
    s=input()
    q=int(input())
    s=deque(s)
    inv=False
    for i in range(q):
        que=input()
        if que[0]=='1':
            inv=not(inv)
        else:
            f=que[2]
            if (f=='1' and not(inv)) or (f=='2' and inv):
                s.appendleft(que[4])
            else:
                s.append(que[4])
    if inv:s.reverse()
    print(*s,sep='')



if __name__=='__main__':
    main()