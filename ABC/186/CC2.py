import sys
def input(): return sys.stdin.readline().rstrip()

def sinsu(n, k):#nのk進数表記を求める
    bi = ''
    while n != 0:
        bi += str(n%abs(k))
        if k < 0: 
            n = -(-n//k)
        else:
            n = n//k
    return bi[::-1]

from itertools import accumulate

def main():
    n = int(input())
    lis = [0]* (n + 1)
    for k in range(1, n + 1):
        if not (('7' in str(k)) or ('7' in sinsu(k, 8))):
            lis[k] += 1
    lis_accum = list(accumulate(lis))
    
    print(lis_accum)


if __name__=='__main__':
    main()