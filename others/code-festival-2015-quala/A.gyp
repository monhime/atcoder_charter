import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    s=input()
    print(s[:-1]+"5")

if __name__=='__main__':
    main()