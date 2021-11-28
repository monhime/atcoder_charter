import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    s=input()
    ans=1
    for i in range(n-1):
        if s[i+1]!=s[i]:ans+=1
    print(ans)

if __name__=='__main__':
    main()