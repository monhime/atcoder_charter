import sys
def input(): return sys.stdin.readline().rstrip()
from collections import Counter
def main():
    n=int(input())
    s=input()
    ss=Counter(s)
    if ss['R']>ss['B']:
        print("Yes")
    else:
        print("No")

if __name__=='__main__':
    main()