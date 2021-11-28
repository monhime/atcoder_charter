import sys
def input(): return sys.stdin.readline().rstrip()
import numpy as np
def main():
    h,w=map(int,input().split())
    S=[input() for _ in range(h)]
    Sharp=np.ones((h,w),int)
    L=np.zeros((h,w),int)
    R=np.zeros((h,w),int)
    U=np.zeros((h,w),int)
    D=np.zeros((h,w),int)
    for i in range(h):
        for j in range(w):
            if S[i][j]=='#':
                Sharp[i][j]=0
                continue
    D[0,:]=np.ones(w,int)*Sharp[0,:]
    for i in range(1,h-1): 
        D[i,:]=(D[i-1,:]+1)*Sharp[i,:]
    U[h-1,:]=np.ones(w,int)*Sharp[h-1,:]
    for i in range(h-2,-1,-1):
        U[i,:]=(U[i+1,:]+1)*Sharp[i,:]
    L[:,0]=np.ones(h,int)*Sharp[:,0]
    for i in range(1,w-1):
        L[:,i]=(L[:,i-1]+1)*Sharp[:,i]
    R[:,w-1]=np.ones(h,int)*Sharp[:,w-1]
    for i in range(w-2,-1,-1):
        R[:,i]=(R[:,i+1]+1)*Sharp[:,i]
    print(np.max((L+R+U+D)*Sharp+1))


if __name__=='__main__':
    main()