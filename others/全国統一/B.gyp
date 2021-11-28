import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    a=input()
    b=input()
    c=input()
    ans=0
    for i in range(n):
        if a[i]!=b[i]:
            if b[i]!=c[i] and a[i]!=c[i]:
                ans+=2
            elif (b[i]!=c[i] and a[i]==c[i]) or b[i]==c[i]:
                ans+=1
        else:
            if b[i]!=c[i]:
                ans+=1
    print(ans)

if __name__=='__main__':
    main()