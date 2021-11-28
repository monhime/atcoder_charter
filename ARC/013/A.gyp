import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,m,l=map(int,input().split())
    p,q,r=map(int,input().split())
    print(max((n//p)*(m//q)*(l//r),(m//p)*(n//q)*(l//r),(n//p)*(l//q)*(m//r),(m//p)*(l//q)*(n//r),(l//p)*(m//q)*(n//r),(l//p)*(n//q)*(m//r)))

if __name__=='__main__':
    main()