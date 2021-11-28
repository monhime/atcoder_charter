import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    s=input()
    ans=0
    for i,ss in enumerate(s):
        if i%2==1:
            ans-=int(ss)
        else:
            ans+=int(ss)
    print(ans)

if __name__=='__main__':
    main()