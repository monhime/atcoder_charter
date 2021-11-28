import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,c,k=map(int,input().split())
    ans=0
    person=0
    wait=-10**9
    T=[int(input())for _ in range(n)]
    T.sort()
    for i in range(n):
        if T[i]-wait<=k and person+1<=c:
            person+=1
        else:
            ans+=1
            person=1
            wait=T[i]
    print(ans)

if __name__=='__main__':
    main()