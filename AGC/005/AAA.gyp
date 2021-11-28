import sys
def input(): return sys.stdin.readline().rstrip()
from collections import deque
def main():
    X=input()
    stack=deque()
    for x in X:
        if x=='S' or (x=='T' and (not stack or stack[-1]=='T')):
            stack.append(x)
        elif stack and stack[-1]=='S':
            stack.pop()
    print(len(stack))
if __name__=='__main__':
    main()