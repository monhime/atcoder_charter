import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,a,b=map(int,input().split())
    if (b-a-1)%2:print("Alice")
    else:print("Borys")

if __name__=='__main__':
    main()