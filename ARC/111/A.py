import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n, m = map(int,input().split())
    cunt = 1
    ans = []
    while cunt < n:
        x = (10 ** cunt//m) % m 
        if x in ans:
            idx = ans.index(x)
            cir = cunt - idx - 1
            print(ans[idx + (n - idx) % cir])
            print(ans, cunt)
            break
        ans.append(x)
        cunt += 1
    else:
        print((10 ** n//m) % m)

if __name__=='__main__':
    main()