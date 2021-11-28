import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n = int(input())
    d1_0, d2_0 = -1, -2
    d1_1, d2_1 = -1, -2
    d1_2, d2_2 = -1, -2
    for i in range(n):
        d1_2, d2_2 = d1_1, d2_1
        d1_1, d2_1 = d1_0, d2_0
        d1_0, d2_0 = map(int,input().split())
        if d1_0 == d2_0 and d1_1 == d2_1 and d1_2 == d2_2:
            print("Yes")
            sys.exit()
    print("No")

if __name__=='__main__':
    main()