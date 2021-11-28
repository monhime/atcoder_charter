import sys
def input(): return sys.stdin.readline().rstrip()
from bisect import bisect_left,bisect
def main():
    n, t = map(int,input().split())
    A  = list(map(int,input().split()))

    A_first = [0] * (1 << (n // 2))
    for bit in range(1 << n // 2):#2**n通りのbit_n番目を探索
        sum_n = 0 
        for i in range(n // 2):
            mask = 1 << i 
            if bit & mask: # bitのi桁目が1なら
                sum_n += A[i]
        A_first[bit] = sum_n
    
    A_second = [0] * (1 << (n - n // 2))
    for bit in range(1 << (n - n // 2)):#2**n通りのbit_n番目を探索
        sum_n = 0 
        for i in range(n - n // 2):
            mask = 1 << i 
            if bit & mask: # bitのi桁目が1なら
                sum_n += A[i + n // 2] 
        A_second[bit] = sum_n

    A_second.sort()
    ans = 0
    for a_f in A_first:
        if a_f > t:
            continue
        ans = max(ans, a_f + A_second[max(bisect(A_second, t - a_f) - 1, 0)])
    print(ans)


if __name__=='__main__':
    main()