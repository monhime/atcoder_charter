import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,k,=map(int,input().split())
    R=[int(_) for _ in input().split()]
    R.sort()
    R=R[n-k:]
    rate=0
    for r in R:
        rate=(rate+r)/2
    print(rate)

if __name__=='__main__':
    main()