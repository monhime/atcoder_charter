import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    s=input()
    print(s[:-8])

if __name__=='__main__':
    main()