import sys
def input(): return sys.stdin.readline().rstrip()
from collections import deque
def main():
    k=int(input())
    que=deque([1,2,3,4,5,6,7,8,9])
    for _ in range(k-1):
        q=que.popleft()
        if q%10>0:que.append(10*q+q%10-1)
        que.append(10*q+q%10)
        if q%10<9:que.append(10*q+q%10+1)
    print(que[0])


if __name__=='__main__':
    main()