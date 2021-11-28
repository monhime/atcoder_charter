import sys
import math
import copy
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
# sys.setrecursionlimit(1000000)


def input(): return sys.stdin.readline().rstrip()


def main():
    mod = 10**9 + 7  # 998244353
    inf = math.inf

    k = int(input())
    lis = []
    len_lis = 0
    keta = 1
    lis_temp = []
    while True:
        if len_lis > k:
            print(lis[k - 1])
            # print(lis)
            sys.exit()

        if keta == 1:
            for i in range(1, 10):
                lis_temp.append(str(i))
                len_lis += 1
                lis = lis_temp
        else:
            lis_temp_2 = []
            for l in lis_temp:
                if l[-1] == "0":
                    lis_temp_2.append(l + "0")
                    lis_temp_2.append(l + "1")
                    len_lis += 2
                elif l[-1] == "9":
                    lis_temp_2.append(l + "8")
                    lis_temp_2.append(l + "9")
                    len_lis += 2
                else:
                    lis_temp_2.append(l + str(int(l[-1]) - 1))
                    lis_temp_2.append(l + str(int(l[-1])))
                    lis_temp_2.append(l + str(int(l[-1]) + 1))
                    len_lis += 3
            lis += lis_temp_2
            lis_temp = lis_temp_2
        keta += 1


if __name__ == '__main__':
    main()
