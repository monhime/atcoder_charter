import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,k=map(int,input().split())
    s=input()
    cunt=0
    for i in range(n-1):
        if s[i]!=s[i+1]:
            cunt+=1
    print(n-1-cunt+min(2*k,cunt))

if __name__=='__main__':
    main()