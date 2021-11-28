import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    A=[int(_) for _ in input().split()]
    A.sort(reverse=True)
    sum_a=0
    for i in range(n):
        sum_a+=A[2*i+1]
    print(sum_a)

if __name__=='__main__':
    main()