import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n = int(input())
    for a in range(1, 100):
        for b in range(1, 100):
            if 3**a + 5**b == n:
                print(a, b)
                sys.exit()
    else:
        print(-1)

if __name__=='__main__':
    main()