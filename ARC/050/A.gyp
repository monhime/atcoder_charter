import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    c,cc=input().split()
    if cc==chr(ord(c)+32):
        print("Yes")
    else:print("No")

if __name__=='__main__':
    main()