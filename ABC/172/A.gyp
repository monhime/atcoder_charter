import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    a = int(input())
    print(a+a**2+a**3)

if __name__=='__main__':
    main()