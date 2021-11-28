import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    new_s=""
    i=0
    if n==0:
        print(0)
        sys.exit()
    while n:
        x=(n>>i)&1
        new_s=str(x)+new_s
        n-=x*(-2)**i
        i+=1
    print(new_s)


if __name__=='__main__':
    main()