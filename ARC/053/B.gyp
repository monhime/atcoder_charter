import sys
def input(): return sys.stdin.readline().rstrip()
from collections import Counter
def main():
    s=input()
    sc=list(Counter(s).items())
    cunt_odd=0
    for ss in sc:
        if ss[1]%2==1:
            cunt_odd+=1
    len_s=len(s)
    if cunt_odd>0:
        print((len_s-cunt_odd)//2//cunt_odd*2+1)
    else:
        print(len_s)

if __name__=='__main__':
    main()