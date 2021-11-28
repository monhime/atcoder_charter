import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,q=map(int,input().split())
    s=input()
    lis=[0]*(n+1) 
    for i in range(n-1):
        if s[i:i+2]=="AC":
            lis[i+1]+=1
        lis[i+2]=lis[i+1]
    for i in range(q):
        l,r=map(int,input().split())
        print(lis[r-1]-lis[l-1])


if __name__=='__main__':
    main()