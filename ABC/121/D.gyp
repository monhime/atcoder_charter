import sys
def input(): return sys.stdin.readline().rstrip()

def main():
    a,b=map(int,input().split())
    x=(((b-1)//2)-(a-1)//2)%2
    if a%2==0:
        if b%2==0:print(x^b)
        else:print(x)
    else:
        if b%2==0:print(a^x^b)
        else:print(a^x)

if __name__=='__main__':
    main()