import sys
def input(): return sys.stdin.readline().rstrip()
def make_divisors(n):
    divisors = []
    for i in range(1,int(n**0.5)+1):
        if n%i==0:
            divisors.append(i)
            if i!=n//i:
                divisors.append(n//i)
    divisors.sort()
    return divisors
import bisect
def main():
    n,m=map(int,input().split())
    div=make_divisors(m)
    print(div[bisect.bisect(div,m//n)-1])
    

if __name__=='__main__':
    main()