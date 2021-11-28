import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    s=input()
    for ans in ("SS","SW","WS","WW"):
        for c in s[1:]:
            if ans[-1]=="S":
                ans+="W" if (ans[-2]=="W")^(c=="x") else "S"
            else:
                ans+="S" if (ans[-2]=="W")^(c=="x") else "W"
        if ans[0]==ans[-1] and (((ans[0]=="W")^(s[0]=="x"))^(ans[-2]==ans[1])):
            print(ans[:-1])
            sys.exit()
    print(-1)


if __name__=='__main__':
    main()