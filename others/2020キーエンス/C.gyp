import sys
def input(): return sys.stdin.readline().rstrip()
import numpy as np
def main():
    n,k,s=map(int,input().split())
    ans=np.array([0]*n)
    ans[:k]+=s
    if s!=10**9:
        ans[k:]+=10**9
    else:
        ans[k:]+=10**9-1
    print(*ans)

if __name__=='__main__':
    main()