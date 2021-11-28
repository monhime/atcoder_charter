import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,k=map(int,input().split())
    if k%2==0:
        print((n//k)**3+((n+k//2)//k)**3)
    else:
        print((n//k)**3)
    
            

if __name__=='__main__':
    main()