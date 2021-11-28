import sys
def input(): return sys.stdin.readline().rstrip()
import numpy as np
def main():
    n=int(input())
    A=np.array([int(_) for _ in input().split()])
    while A.size>1:
        min_A=np.min(A)
        A=np.fmod(A,min_A)
        A=A[A>0]
        A=np.append(A,min_A)
    print(A[0])
    

if __name__=='__main__':
    main()