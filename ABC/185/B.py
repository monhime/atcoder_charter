import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n, m, t = map(int,input().split())
    bat = n
    pre_t = 0
    for i in range(m):
        a, b = map(int,input().split())
        bat -= a - pre_t
        if bat <= 0:
            print("No")
            sys.exit()
        bat = min(bat + b - a, n)
        pre_t = b
    
    bat -= t - pre_t

    if bat > 0:
        print("Yes")
    else:
        print("No")

if __name__=='__main__':
    main()