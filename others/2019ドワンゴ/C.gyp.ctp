import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    A=[int(_) for _ in input().split()]
    ave = sum(A)/n
    A.sort()
    d=1000
    for i,a in enumerate(A):
        if abs(a-ave)<d:
            d=abs(a-ave)
        else:
            print()

if __name__=='__main__':
    main()