import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    A=[int(_) for _ in input().split()]
    if len(set(A))==n:print("YES")
    else:print("NO")

if __name__=='__main__':
    main()