import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    x=input()
    s=input()
    ans=""
    for ss in s:
        if ss!=x:
            ans+=ss
    print(ans)

if __name__=='__main__':
    main()