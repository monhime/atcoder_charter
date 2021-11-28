import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    a, b, c = map(int,input().split())
    k = int(input())
    cunt = 0
    while a >= b:
        b *= 2
        cunt += 1
    while b >= c:
        c *= 2
        cunt += 1
    if cunt > k:
        print("No")
    else:
        print("Yes")
    


if __name__=='__main__':
    main()