import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    k=int(input())
    if k <= n//2:
        print("YES")
    else:print("NO")
    

if __name__=='__main__':
    main()