import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,k=map(int,input().split())
    H=[int(_) for _ in input().split()]
    H.sort(reverse=True)
    print(sum(H[k:]))

if __name__=='__main__':
    main()