import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n = int(input())
    if n%1000>0:
        print(1000-n%1000)
    else:
        print(0)

if __name__=='__main__':
    main()