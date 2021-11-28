import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    X=[int(_) for _ in input().split()]
    sum=0
    for x in X:
        if x == 1:sum+=300000
        elif x==2:sum+=200000
        elif x==3:sum+=100000
    if X[0]==X[1] and X[0]==1:
        sum+=400000
    print(sum)

if __name__=='__main__':
    main()