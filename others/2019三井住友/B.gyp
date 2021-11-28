import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    for x in range(n//2,n+1):
        if x*1.08//1==n:
            print(x)
            break
    else:print(":(")

if __name__=='__main__':
    main()