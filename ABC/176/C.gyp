import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n = int(input())
    A = list(map(int,input().split()))
    high = 0
    ans = 0
    for a in A:
        if high > a:
            ans += high - a
        elif high < a:
            high = a
    print(ans)

if __name__=='__main__':
    main()