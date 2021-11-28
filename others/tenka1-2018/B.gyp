import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    a,b,k=map(int,input().split())
    for i in range(k):
        if i%2==0:
            a=a//2*2
            b+=a//2
            a=a//2
        else:
            b=b//2*2
            a+=b//2
            b=b//2           
    print(a,b)

if __name__=='__main__':
    main()