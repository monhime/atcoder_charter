import sys
from collections import Counter
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    s=input()
    c_s=Counter(s)
    sum_a=0
    for diff in range(1,(n-1)//2+1):
        for i in range(n-2*diff):
            if s[i]!=s[i+diff] and s[i+diff]!=s[i+2*diff] and s[i]!=s[i+2*diff]:
                sum_a+=1
    print(c_s['R']*c_s['G']*c_s['B']-sum_a)

if __name__=='__main__':
    main()