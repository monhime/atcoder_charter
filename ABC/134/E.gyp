import sys
def input(): return sys.stdin.readline().rstrip()
import bisect
def make_LIS(L):
    LIS=[L[0]]
    for i in range(1,len(L)):
        if L[i]>=LIS[-1]:#広義単調増加なら>=に
            LIS.append(L[i])
        else:
            LIS[bisect.bisect_right(LIS,L[i])]=L[i]#広義単調増加の場合，必ずbisect_right
    return len(LIS)
def main():
    n=int(input())
    A=[int(input())for _ in range(n)]
    print(make_LIS(A[::-1]))

if __name__=='__main__':
    main()