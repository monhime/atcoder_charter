import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,k=map(int,input().split())
    sum_a=0
    for i in range(n):
        sum_a+=int(input())
        if sum_a>=k:
            print(i+1)
            sys.exit()


if __name__=='__main__':
    main()