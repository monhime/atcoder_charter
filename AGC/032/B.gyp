import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    print(n*(n-1)//2-n//2)
    if n%2==1:
        for i in range(1,n):
            for j in  range(i+1,n+1):
                if j==n-i:continue
                print(i,j)
    else:
        for i in range(1,n):
            for j in  range(i+1,n+1):
                if j==n-i+1:continue
                print(i,j)        

if __name__=='__main__':
    main()