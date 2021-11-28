import sys
import numpy as np
def input(): return sys.stdin.readline().rstrip()
def main():
    h, w = map(int,input().split())
    A = [[int(_) for _ in input().split()] for i in range(h)]
    A = np.array(A)
    print(np.sum(A - np.min(A)))

if __name__=='__main__':
    main()