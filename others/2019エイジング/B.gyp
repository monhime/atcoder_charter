import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    a,b=map(int,input().split())
    P=[int(_) for _ in input().split()]
    P.sort()
    cunt1,cunt2,cunt3=0,0,0
    for p in P:
        if p<=a:
            cunt1+=1
        elif a+1<=p and p<=b:
            cunt2+=1
        else:cunt3+=1
    print(min(cunt1,cunt2,cunt3))

if __name__=='__main__':
    main()