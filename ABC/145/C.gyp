import sys
from math import sqrt
from itertools import permutations
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    A =[[int(_) for _ in input().split()] for i in range(n)]
    a_list=list(permutations(A))
    a_len=len(a_list)
    ans_all=0
    for i in range(a_len):
        keiro = a_list[i]
        ans=0
        x0=keiro[0][0]
        y0=keiro[0][1]
        for x1,y1 in keiro[1:]:
            ans+=sqrt((x1-x0)**2+(y1-y0)**2)
        ans_all+=ans
    print(ans_all/a_len)
if __name__=='__main__':
    main()