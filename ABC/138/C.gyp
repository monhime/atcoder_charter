import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    V=[int(_) for _ in input().split()]
    V.sort()
    ss=V[0]
    for i in range(1,n):
        ss=(ss+V[i])/2
    print(ss)

if __name__=='__main__':
    main()