import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,a,b=map(int,input().split())
    if n%(a+b)<=a and n%(a+b)!=0:
        print("Ant")
    else:
        print("Bug")

if __name__=='__main__':
    main()