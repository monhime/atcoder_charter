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

def main():
    n=int(input())
    ans=0
    div_n=make_divisors(n)
    for p in div_n:
        m=(n-p)//p
        if m>0 and n%m==p:
            ans+=m
    print(ans)

if __name__=='__main__':
    main()