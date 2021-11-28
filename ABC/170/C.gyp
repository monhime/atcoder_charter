import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    x,n=map(int,input().split())
    P = list(map(int,input().split()))
    n_lis = [0]*102
    for p in P:
        n_lis[p] += 1
    dis = 0
    while 1:
        if n_lis[x-dis] == 0:
            print(x-dis)
            break
        elif n_lis[x+dis] == 0:
            print(x+dis)
            break
        dis += 1

if __name__=='__main__':
    main()