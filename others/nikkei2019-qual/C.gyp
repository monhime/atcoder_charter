import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    AB=[]
    for i in range(n):
        a,b=map(int,input().split())
        AB.append((a+b,a,b))    
    AB.sort(reverse=True)
    x=sum([-b[2] for b in AB])
    sum_ab=sum([ab[0] for ab in AB[::2]])
    print(x+sum_ab)


if __name__=='__main__':
    main()