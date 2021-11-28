import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    t=int(input())
    n=int(input())
    A=[int(_) for _ in input().split()]
    m=int(input())
    B=[int(_) for _ in input().split()]
    tako=-1
    for i in range(m):
        for ta in range(tako+1,n):
            if B[i]<=A[ta]+t and B[i]>=A[ta]:
                tako=ta
                break
        else:
            print("no")
            break
    else:
        print("yes")


if __name__=='__main__':
    main()