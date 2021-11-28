import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,m=map(int,input().split())
    A=[int(_) for _ in input().split()]
    sum_a=sum(A)
    if sum_a>n:
        print(-1)
    else:
        print(n-sum_a)

if __name__=='__main__':
    main()