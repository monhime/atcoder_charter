import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    a=input()
    b=int(input())
    print(a[(b-1)%len(a)])

if __name__=='__main__':
    main()