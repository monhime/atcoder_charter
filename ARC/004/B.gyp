import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    D=[int(input())for _ in range(n)]
    print(sum(D))
    print(max(2*max(D)-sum(D),0))
if __name__=='__main__':
    main()