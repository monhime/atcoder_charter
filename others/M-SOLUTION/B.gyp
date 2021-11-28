import sys
def input(): return sys.stdin.readline().rstrip()
from collections import Counter
def main():
    s=input()
    s_len=len(s)
    c_s=Counter(s)
    if c_s['o']+(15-s_len)>=8:
        print("YES")
    else:print("NO")

if __name__=='__main__':
    main()