import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    s,w=map(int,input().split())
    if s<=w:
        print("unsafe")
    else:
        print("safe")

if __name__=='__main__':
    main()