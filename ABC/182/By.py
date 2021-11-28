import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n = int(input())
    A = list(map(int,input().split()))
    ans = 2
    ans_cunt = 0
    for k in range(2, max(A) + 1):
        cunt = 0
        for a in A:
            if a % k == 0:
                cunt += 1
        if ans_cunt < cunt:
            ans_cunt = cunt
            ans = k
    print(ans)

if __name__=='__main__':
    main()