import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n = int(input())
    A = list(map(int,input().split()))
    a_0 = max(A[0:2**(n - 1)])
    a_0_i = A.index(a_0)
    a_1 = max(A[2**(n - 1):2**n])
    a_1_i = A.index(a_1)
    if a_0 < a_1:
        print(a_0_i + 1) 
    else:
        print(a_1_i + 1)

if __name__=='__main__':
    main()