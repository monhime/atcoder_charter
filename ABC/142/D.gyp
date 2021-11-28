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

import math
def is_prime(n):
    if n==1:return False
    for k in range(2,int(math.sqrt(n))+1):
        if n%k==0:
            return False
    return True
    
def main():
    a,b=map(int,input().split())
    a_s,b_s=set(make_divisors(a)),set(make_divisors(b))
    c_s=a_s&b_s
    ans=[]
    c=list(c_s)
    c.sort()
    ans=1
    for cc in c:
        if is_prime(cc):
            ans+=1
    print(ans)


if __name__=='__main__':
    main()