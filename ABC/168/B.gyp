import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    k=int(input())
    s=input()
    if len(s)<=k:print(s)
    else:
        print(s[:k]+"...")

if __name__=='__main__':
    main()