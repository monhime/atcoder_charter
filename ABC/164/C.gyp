import sys
def input(): return sys.stdin.readline().rstrip()
from collections import Counter
def main():
    n=int(input())
    S=[input() for _ in range(n)] 
    sc=Counter(S)
    print(len(sc.items()))
if __name__=='__main__':
    main()