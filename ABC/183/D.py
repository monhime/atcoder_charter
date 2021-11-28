import sys
def input(): return sys.stdin.readline().rstrip()
from itertools import accumulate
def main():
    n, w = map(int,input().split())
    STP = [[int(_) for _ in input().split()] for i in range(n)]
    Lis = [0] * (2*10**5 + 2)
    for stp in STP:
        Lis[stp[0]] += stp[2]
        Lis[stp[1]] -= stp[2]
    for i in range(2*10**5 + 1):
        if Lis[i] > w:
            print("No")
            break
        Lis[i + 1] += Lis[i]
    else:
        print("Yes")

if __name__=='__main__':
    main()