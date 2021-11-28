import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    s=input()
    t=input()
    if s==t:
        print(0)
        sys.exit()
    for i in range(len(s)):
        s=s[-1]+s[:-1]
        if s==t:
            print(i+1)
            sys.exit()
    else:
        print(-1)

if __name__=='__main__':
    main()