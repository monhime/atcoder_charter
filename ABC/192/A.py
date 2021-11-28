import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    x = int(input())
    if x % 100 == 0:
        print(100)
    else:
        print(100 - x%100)

if __name__=='__main__':
    main()