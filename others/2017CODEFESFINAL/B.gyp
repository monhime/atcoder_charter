import sys
def input(): return sys.stdin.readline().rstrip()
from collections import Counter
def main():
    s=input()
    s_c=Counter(s)
    if len(s)==1:
        print("YES")
    elif len(s)==2 and s[0]!=s[1]:
        print("YES")
    elif len(s)==3 and len(s_c.items())==3:
        print("YES")
    else:
        s_list=sorted(s_c.values())
        if len(s_list)==3:
            if s_list[2]-s_list[0]<=1:
                print("YES")
            else:
                print("NO")
        else:
            print("NO")

if __name__=='__main__':
    main()