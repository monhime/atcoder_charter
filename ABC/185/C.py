import sys
def input(): return sys.stdin.readline().rstrip()
from operator import mul
from functools import reduce
def combinations_count(n, r): #nCr
    #Reference: https://note.nkmk.me/python-math-factorial-permutations-combinations/
    r = min(r, n - r)
    numer = reduce(mul, range(n, n - r, -1), 1)
    denom = reduce(mul, range(1, r + 1), 1)
    return numer // denom

def main():
    l = int(input())
    #print(combinations_count(l - 1, 11))
    print(comb(l - 1, 11, exact = True))

if __name__=='__main__':
    main()