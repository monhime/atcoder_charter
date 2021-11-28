import sys
def input(): return sys.stdin.readline().rstrip()
from collections import Counter
def main():
    s=input()
    s=s.lower()
    ict=0
    for ss in s:
        if ss=="i" and ict==0:
            ict+=1
        elif ss=="c" and ict==1:
            ict+=1
        elif ss=="t" and ict==2:
            print("YES")
            break
    else:print("NO")

if __name__=='__main__':
    main()