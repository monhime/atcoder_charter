import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    s=input()
    cunt_b=0
    ans=0
    for ss in s:
        if ss=='B':
            cunt_b+=1
        else:
            ans+=cunt_b
    print(ans)

if __name__=='__main__':
    main()