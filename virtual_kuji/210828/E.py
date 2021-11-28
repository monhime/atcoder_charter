import sys, math, copy
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
sys.setrecursionlimit(1000000)
def input(): return sys.stdin.readline().rstrip()
def main():
    mod = 10**9 + 7
    inf = 10**10
    
    s1 = input()
    s2 = input()
    s3 = input()
    s = s1 + s2 + s3
    s_c = Counter(s)
    s_c_k = list(s_c.keys())
    s_c_len = len(s_c_k)

    C_dict = dict()
    N_lis = [False] * 10
    def f(idx): #idx文字目の数字の当て方
        if idx < s_c_len:
            cur_c = s_c_k[idx]
            for c in range(10):  
                if N_lis[c]:
                    continue
                if c == 0 and (s1[0] == cur_c or s2[0] == cur_c or s3[0] == cur_c):
                    continue
                C_dict[cur_c] = c
                N_lis[c] = True
                # print(C_dict)
                # print(N_lis)
                f(idx + 1)
                del C_dict[cur_c]
                N_lis[c] = False
        else:
            n1_s = ""
            for c1 in s1:
                n1_s += str(C_dict[c1])
            n2_s = ""
            for c2 in s2:
                n2_s += str(C_dict[c2])
            n3_s = ""
            for c3 in s3:
                n3_s += str(C_dict[c3])
            #print(n1_s, n2_s, n3_s)
            if int(n1_s) + int(n2_s) == int(n3_s):
                print(n1_s)
                print(n2_s)
                print(n3_s)
                sys.exit()
    f(0)
    print("UNSOLVABLE")
    
if __name__=='__main__':
    main()