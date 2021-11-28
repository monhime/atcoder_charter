import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    n=(n-1)%40+1
    if n<=20:
        print(n)
    else:
        print(41-n)

if __name__=='__main__':
    main()