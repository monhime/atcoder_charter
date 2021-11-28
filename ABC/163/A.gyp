import sys
def input(): return sys.stdin.readline().rstrip()
import numpy as np
def main():
    r=int(input())
    print(2*np.pi*r)

if __name__=='__main__':
    main()