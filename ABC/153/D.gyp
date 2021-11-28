import sys
import math
def input(): return sys.stdin.readline().rstrip()
def main():
    h=int(input())
    print(2**(int(math.log2(h))+1)-1)

if __name__=='__main__':
    main()