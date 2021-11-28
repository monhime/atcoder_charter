import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,k=map(int,input().split())
    T=[int(input())for _ in range(n)]
    cunt=T[0]+T[1]
    for i in range(2,n):
        cunt+=T[i]
        if cunt<k:
            print(i+1)
            break
        cunt-=T[i-2]
    else:print(-1)

if __name__=='__main__':
    main()