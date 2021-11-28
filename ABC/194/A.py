import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    a, b = map(int,input().split())
    a = a + b
    if a >= 15 and b >= 8:
        print(1)
    elif a >= 10 and b >= 3:
        print(2)
    elif a >= 3:
        print(3)
    else:
        print(4)

if __name__=='__main__':
    main()