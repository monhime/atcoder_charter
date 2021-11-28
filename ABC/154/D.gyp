import sys
def input(): return sys.stdin.readline().rstrip()
import numpy as np
def main():
    n,k=map(int,input().split())
    P=np.array([int(_) for _ in input().split()])
    PP=(P+1)/2
    PP_cum=np.cumsum(PP)
    PP_cum=np.insert(PP_cum,0,0)
    print(np.max(PP_cum[k:]-PP_cum[:n-k+1]))

if __name__=='__main__':
    main()