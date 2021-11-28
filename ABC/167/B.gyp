import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    a,b,_,k=map(int,input().split())
    if k<=a:
        print(k)
    elif k>a and k<=a+b:
        print(a)
    else:
        print(a-(k-a-b))
if __name__=='__main__':
    main()