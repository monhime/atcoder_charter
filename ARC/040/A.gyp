import sys
def input(): return sys.stdin.readline().rstrip()
from collections import Counter
def main():
    n=int(input())
    s=""
    for i in range(n):
        s+=input()
    s=Counter(s)
    if s['R']>s['B']:print("TAKAHASHI")
    elif s['R']<s['B'] :print("AOKI")
    else:print("DRAW")

if __name__=='__main__':
    main()