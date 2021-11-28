from operator import mul
from functools import reduce

def cmb(n,r):
    #n<10^4で最速s
    r = min(n-r,r)
    if r == 0: return 1
    over = reduce(mul, range(n, n - r, -1))
    under = reduce(mul, range(1,r + 1))
    return over // under

n,m=map(int,input().split())
if n>=2 and m>=2:print(cmb(n,2)+cmb(m,2))
elif n>=2:print(cmb(n,2))
elif m>=2:print(cmb(m,2))
else:print(0)