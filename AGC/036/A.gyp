import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    print(0,0,10**9,1,-10**9*(-n//10**9)-n,-(-n//10**9))
if __name__=='__main__':
    main()