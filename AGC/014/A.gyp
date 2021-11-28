import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    a,b,c=map(int,input().split())
    cunt=0
    if a==b and b==c and a%2==0:
        print(-1)
        sys.exit()
    while True:
        if a%2 or b%2 or c%2:
            print(cunt)
            break
        cunt+=1
        a1,b1,c1=a,b,c
        a=(b1+c1)//2
        b=(a1+c1)//2
        c=(a1+b1)//2
        print(a,b,c)

if __name__=='__main__':
    main()