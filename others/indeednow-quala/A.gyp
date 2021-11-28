import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    a=input()
    b=input()
    print(len(a)*len(b))

if __name__=='__main__':
    main()