import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    _,l=map(int,input().split())
    s=input()
    cunt=1
    ans=0
    for ss in s:
        if ss=='+':cunt+=1
        else:cunt-=1

        if cunt>l:
            ans+=1
            cunt=1
    print(ans)
        


if __name__=='__main__':
    main()