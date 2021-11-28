import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    s=input().split()
    ans=""
    for ss in s:
        if ss=="Right":
            ans+="> "
        elif ss=="Left":
            ans+="< "
        else:
            ans+="A "
    print(ans[:-1])
if __name__=='__main__':
    main()