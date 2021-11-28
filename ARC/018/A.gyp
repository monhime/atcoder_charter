import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    h,b=map(float,input().split())
    print("{}".format((h/100)**2*b))

if __name__=='__main__':
    main()