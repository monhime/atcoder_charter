import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n = int(input())
    ans = ""
    while n > 0:
        n -= 1
        ans = chr(n%26 + ord('a')) + ans
        n //= 26
    print(ans)

if __name__=='__main__':
    main()