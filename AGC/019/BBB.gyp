import sys
def input(): return sys.stdin.readline().rstrip()
from collections import Counter
def main():
    A=input()
    ac=list(Counter(A).values())
    len_a=len(A)
    ans=len_a*(len_a-1)//2
    for acc in ac:
        ans-=acc*(acc-1)//2
    print(ans+1)

if __name__=='__main__':
    main()