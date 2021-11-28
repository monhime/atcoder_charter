import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    s=input()
    t=input()
    if s==t[:-1]:
        print("Yes")
    else:
        print("No")

if __name__=='__main__':
    main()