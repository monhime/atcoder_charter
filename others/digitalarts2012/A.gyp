import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    S=input().split()
    n=int(input())
    for i in range(n):
        t=input()
        for j,s in enumerate(S):
            if s==t:
                S[j]='*'*len(t)
            elif len(s)==len(t):
                for k,tt in enumerate(t):
                    if tt!='*' and tt!=s[k]:
                        break
                else:
                    S[j]='*'*len(t)
    print(*S)

if __name__=='__main__':
    main()