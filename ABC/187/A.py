import sys
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
        ans3 = max(ans3, x)
    print(ans1)
    print(ans2**0.5)
    print(ans3)

if __name__=='__main__':
    main()