import sys
def input(): return sys.stdin.readline().rstrip()
import numpy as np
def main():
    a,b,c=map(int,input().split())
    print(np.pi*((a+b+c)**2-max(0,a-(b+c))**2-max(0,c-(b+a))**2-max(0,b-(a+c))**2))

if __name__=='__main__':
    main()