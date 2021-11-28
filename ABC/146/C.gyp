import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    a,b,x=map(int,input().split())
    if a+b>x:
        print(0)
        sys.exit()
    for i in range(10,0,-1):#d(N)
        if x-b*i<a*10**(i-1):
            continue
        if i==10:
            print(10**9)
        else:
            print(min(10**i-1,(x-b*i)//a))
        sys.exit()

if __name__=='__main__':
    main()