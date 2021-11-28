import time

from operator import mul
from functools import reduce

n,r=map(int,input().split())

def cmb1(n,r):
    r = min(n-r,r)
    if r == 0: return 1
    over = reduce(mul, range(n, n - r, -1))
    under = reduce(mul, range(1,r + 1))
    return over // under

start1 = time.time()
a = cmb1(n, r)
elapsed_time1 = time.time() - start1
print ("elapsed_time1:{0}".format(elapsed_time1) + "[sec]")

def cmb2(n, r):
    if n - r < r: r = n - r
    if r == 0: return 1
    if r == 1: return n

    numerator = [n - r + k + 1 for k in range(r)]
    denominator = [k + 1 for k in range(r)]

    for p in range(2,r+1):
        pivot = denominator[p - 1]
        if pivot > 1:
            offset = (n - r) % p
            for k in range(p-1,r,p):
                numerator[k - offset] /= pivot
                denominator[k] /= pivot

    result = 1
    for k in range(r):
        if numerator[k] > 1:
            result *= int(numerator[k])

    return result



start2 = time.time()
a = cmb2(n, r)
elapsed_time2 = time.time() - start2
print ("elapsed_time2:{0}".format(elapsed_time2) + "[sec]")
