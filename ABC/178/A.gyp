import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    x = int(input())
    if x == 0:
        print(1)
    else:
        print(0)

if __name__=='__main__':
    main()