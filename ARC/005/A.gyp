import sys
def input(): return sys.stdin.readline().rstrip()
from collections import Counter
def main():
    n=int(input())
    W=input()
    W=[_ for _ in W[:-1].split()]
    W_set=Counter(W)
    print(W_set["TAKAHASHIKUN"]+W_set["Takahashikun"]+W_set["takahashikun"])

if __name__=='__main__':
    main()