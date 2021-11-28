import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    S=[input() for _ in range(15)]
    S.sort()
    print(S[6])

if __name__=='__main__':
    main()