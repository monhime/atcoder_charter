import sys
from functools import reduce
def input(): return sys.stdin.readline().rstrip()
def main():
    n = int(input())
    X = list(map(int,input().split()))
    ans1 = 0
    ans2 = 0
    ans3 = -1000000
    for x in X:
        ans1 += abs(x)
        ans2 += x**2
        ans3 = max(ans3, abs(x))
    print(reduce((lambda x, y: abs(x) + abs(y)), X))
    print(reduce((lambda x, y: x**2 + y**2), X)**0.5)
    print(reduce((lambda x, y: max(abs(x), abs(y))), X))

if __name__=='__main__':
    main()