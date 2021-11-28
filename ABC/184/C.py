import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    r1, c1 = map(int,input().split())
    cunt_guki_1 = (r1%2)^(c1%2)
    r2, c2 = map(int,input().split())
    cunt_guki_2 = (r2%2)^(c2%2)
    if r1 == r2 and c1 == c2:
        print(0)
    elif abs(r1 - r2) + abs(c1 - c2) <= 3 or r1 + c1 == r2 + c2 or r1 - c1 == r2 - c2: #1回で行ける
        print(1) 
    elif abs(r1 - r2) + abs(c1 - c2) <= 6 or cunt_guki_1 == cunt_guki_2 or abs(abs(r2 - r1) - abs(c2 - c1)) <= 3:
        print(2) 
    else:
        print(3)

if __name__=='__main__':
    main()