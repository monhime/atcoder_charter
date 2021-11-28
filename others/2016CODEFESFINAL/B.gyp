import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    while n>0:
        right=n+1
        left=1
        while right-left>0:
            k=(right+left)//2
            if n<k*(k-1)//2+1:
                right=k
                continue
            elif k*(k+1)//2<n:
                left=k
                continue
            break
        print(k)
        n-=k



if __name__=='__main__':
    main()