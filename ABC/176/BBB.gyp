import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    S = input()
    n = 0
    for s in S:
        n += int(s)
    if n%9 == 0:
        print("Yes")
    else:
        print("No")


if __name__=='__main__':
    main()