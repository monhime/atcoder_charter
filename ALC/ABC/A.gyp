import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    k  = int(input())
    ans = ""
    for i in range(k):
        ans += "ACL"
    print(ans)

if __name__=='__main__':
    main()