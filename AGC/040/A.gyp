import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    s=input()
    n=len(s)
    A=[0]*(n+1)
    for i in range(n):
        if s[i]=="<":
            A[i+1]=A[i]+1
    for i in range(n):
        if s[n-i-1]==">":
            A[n-i-1]=max(A[n-i-1],A[n-i]+1)
    print(sum(A))

if __name__=='__main__':
    main()