import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    H=[int(_) for _ in input().split()]
    H[0]-=1
    for i in range(1,n):
        if H[i-1]<H[i]:H[i]-=1
        elif H[i-1]>H[i]:
            print("No")
            break
    else:print("Yes")
if __name__=='__main__':
    main()