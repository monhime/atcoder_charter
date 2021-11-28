import sys
def input(): return sys.stdin.readline().rstrip()
from collections import Counter
def main():
    X=input()
    cunt=0
    cunt_s=0
    for x in X:
        if x=='S':
            cunt_s+=1
        elif cunt_s>0:
            cunt_s-=1
        else:
            cunt+=1
    print(cunt+cunt_s)

if __name__=='__main__':
    main()