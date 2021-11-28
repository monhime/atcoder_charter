import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    s=input()
    n=len(s)
    flag=-1
    for i in range(n):
        if s[i]=='W':
            flag=i
        else:
            break
    cunt_b=0
    cunt_w=0
    ans=0
    for i in range(n):
        if s[i]=='B':
            cunt_b+=1
        elif cunt_b>0:
            ans+=i-flag-1-cunt_w
            cunt_w+=1
    print(ans)



if __name__=='__main__':
    main()