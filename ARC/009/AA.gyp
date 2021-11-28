import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    sum=0
    for i in range(n):
        a,b=map(int,input().split())
        sum+=a*b
    print(int(sum*1.05//1))

if __name__=='__main__':
    main()
