import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    a,b,k,l=map(int,input().split())
    print(min(k//l*b+(k-k//l*l)*a,(k//l+1)*b))

if __name__=='__main__':
    main()