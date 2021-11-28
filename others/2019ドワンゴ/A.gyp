import sys
def input(): return sys.stdin.readline().rstrip()
import numpy as np
def main():
    n=int(input())
    A=[int(_) for _ in input().split()]
    A=np.array(A)
    meanA=np.mean(A)
    A1=np.abs(A-meanA)
    print(np.argmin(A1))


if __name__=='__main__':
    main()