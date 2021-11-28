import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    for i in range(1001):
        if 100*i<=n and n<=105*i:
            print(1)
            break
    else:print(0)


if __name__=='__main__':
    main()