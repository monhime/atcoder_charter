import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    k,n=map(int,input().split())
    A=[int(_) for _ in input().split()]
    max_len=(k-A[-1])+A[0]
    for i in range(n-1):
        max_len=max(max_len,A[i+1]-A[i])
    print(k-max_len)

if __name__=='__main__':
    main()