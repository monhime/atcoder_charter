import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    
    a, b, c = map(int,input().split())
    print(21 - (a + b + c))

if __name__=='__main__':
    main()