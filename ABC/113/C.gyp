import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,m=map(int,input().split())
    A=[]
    for i in range(m):
        p,y=map(int,input().split())
        A.append((p,y,i))
    A.sort()
    cunt,pre,ans=0,0,[]
    for a in A:
        s1=str(a[0])
        if pre!=a[0]:
            cunt=1
            pre=a[0]
        s2=str(cunt)
        ans.append((a[2],s1.zfill(6)+s2.zfill(6)))
        cunt+=1
    ans.sort()
    for s in ans:
        print(s[1])

if __name__=='__main__':
    main()