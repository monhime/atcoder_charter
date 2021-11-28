import sys
import numba
def input(): return sys.stdin.readline().rstrip()
def main():
    n = int(input())
    ans = 0
    for i in range(1, n+1):
        ans += i*(1 + n//i)*(n//i)//2
    print(ans)



if __name__=='__main__':
    main()