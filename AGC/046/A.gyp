import sys
import math
def input(): return sys.stdin.readline().rstrip()
def main():
    x = int(input())
    xx = x
    ans = 1
    while xx%360 != 0:
        xx += x
        ans += 1
    print(ans )

if __name__=='__main__':
    main()