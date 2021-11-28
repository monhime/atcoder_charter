import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    Z=[tuple(map(int,input().split())) for i in range(n)]
    ans=0
    for i in range(n-1):
        for j in range(i+1,n):
            ans=max(ans,(Z[i][0]-Z[j][0])**2+(Z[i][1]-Z[j][1])**2)
    print(ans**0.5)

if __name__=='__main__':
    main()