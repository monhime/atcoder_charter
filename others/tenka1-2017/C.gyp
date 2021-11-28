import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    for a in range(n//4+1,3501):
        for b in range(n*a//(4*a-n),3501):
            if 4*a*b-n*(a+b)>0 and n*a*b%(4*a*b-n*(a+b))==0:
                print(a,b,n*a*b//(4*a*b-n*(a+b)))
                sys.exit()

if __name__=='__main__':
    main()