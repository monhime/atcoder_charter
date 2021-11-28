import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    x, k, d = map(int,input().split())
    if x < 0:
        x *= -1
    if x >= k*d:
        print(x - k*d)
    else:
        if (k - x//d)%2 == 0:
            print(x - x//d*d)
        else:
            print(-(x - (x//d + 1)*d))


if __name__=='__main__':
    main()