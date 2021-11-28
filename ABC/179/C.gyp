import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n = int(input())
    ans = 0
    for a in range(1,n):
        ans += -(-n//a) - 1
    print(ans)
        

if __name__=='__main__':
    main()