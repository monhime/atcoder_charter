import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    if n%10<7:
        print(n//10*100+n%10*15)
    else:
        print(-(-n//10)*100)

if __name__=='__main__':
    main()