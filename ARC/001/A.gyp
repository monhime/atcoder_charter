import sys
def input(): return sys.stdin.readline().rstrip()
from collections import Counter
def main():
    n=int(input())
    c=input()
    c=Counter(c)
    if len(c)==4:
        print(max(c.values()),min(c.values()))
    else:
        print(max(c.values()),0)
    

if __name__=='__main__':
    main()