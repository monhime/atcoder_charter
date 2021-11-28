import sys
from itertools import permutations
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    P=tuple(map(int,input().split()))
    Q=tuple(map(int,input().split()))
    p_list=list(permutations(range(1,n+1)))
    print(abs(p_list.index(Q)-p_list.index(P)))

if __name__=='__main__':
    main()