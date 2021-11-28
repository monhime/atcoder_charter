import sys
def input(): return sys.stdin.readline().rstrip()
import numpy as np
def main():
    l,r=map(int,input().split())
    ans=2019
    arr1=np.arange(l,r+1).reshape(r-l+1,1)
    arr2=np.arange(l,r+1).reshape(1,r-l+1)
    mat=arr1*arr2
    print(arr1,arr2)
    print(mat)
    mat=mat%2019
    print(mat)
    print(np.amin(mat))

if __name__=='__main__':
    main()