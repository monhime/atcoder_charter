import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    a, b = input().split()
    a = int(a)
    b = int(b[0]+b[2:4])
    print(a*b//100)

if __name__=='__main__':
    main()