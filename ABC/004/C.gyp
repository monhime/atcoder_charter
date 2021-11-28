import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    n=n%30
    if n==0:
        print("123456")
        sys.exit()
    s=[1,2,3,4,5,6]
    for i in range(n):
        left=i%5
        right=i%5+1
        s[left],s[right]=s[right],s[left]
    print(*s,sep='')

if __name__=='__main__':
    main()