import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    k,a,b=map(int,input().split())
    if b-a<=2 or k<=a:
        print(k+1)
    else:
        print(a+(b-a)*((k-a+1)//2)+(k-a+1)%2)


if __name__=='__main__':
    main()