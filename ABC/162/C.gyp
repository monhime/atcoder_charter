import sys
import math
from functools import reduce
def input(): return sys.stdin.readline().rstrip()
def gcd(*numbers):
    return reduce(math.gcd, numbers)
def main():
    k=int(input())
    sum=0
    for i in range(1,k-1):
        for j in range(i+1,k):
            for l in range(j+1,k+1):
                sum+=gcd(i,j,l)*6
    for i in range(1,k+1):
        for j in range(1,k+1):
            if i!=j:
                sum+=gcd(i,j,j)*3
    for i in range(1,k+1):
        sum+=gcd(i,i,i)
    print(sum)

if __name__=='__main__':
    main()