import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,m,a,b=map(int,input().split())
    cunt=n
    for i in range(m):
        if cunt<=a:
            cunt+=b
        cunt-=int(input())
        if cunt<0:
            print(i+1)
            break
    else:print("complete")

if __name__=='__main__':
    main()