import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    s=input()
    if len(s)==2:print(s)
    else:print(s[::-1])

if __name__=='__main__':
    main()