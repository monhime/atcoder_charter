import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    A=[int(_) for _ in input().split()]
    cunt=0
    for a in A:
        if a==cunt+1:cunt+=1
    if 1 in A:
        if n==1 and A[0]==1:print(0)
        else:print(n-cunt)
    else:
        print(-1)
        

if __name__=='__main__':
    main()