import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n = int(input())
    if n % 2 == 0:
        print("White")
    else:
        print("Black")

if __name__=='__main__':
    main()