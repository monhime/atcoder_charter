import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    _,_=input().split()
    aa,a=map(int,input().split())
    if a==1:print(1)
    else:print(0)

if __name__=='__main__':
    main()