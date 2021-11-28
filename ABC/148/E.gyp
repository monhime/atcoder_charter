import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    if n%2==0:
        ans=0
        i=0
        while 10*5**i<=n:
            ans+=n//(10*5**i)
            i+=1
        print(ans)
    else:print(0)

if __name__=='__main__':
    main()