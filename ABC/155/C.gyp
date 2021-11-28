import sys
from collections import Counter
from operator import itemgetter
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    S=[input()for _ in range(n)]
    s_cnt=Counter(S)
    s_list=sorted(list(s_cnt.items()),key=itemgetter(1),reverse=True)
    s_list=[s[0] for s in s_list if s[1]==s_list[0][1]]
    s_list.sort()
    for s in s_list:
        print(s)
if __name__=='__main__':
    main()