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
    x=int(input())
    x_lis=make_divisors(x)
    q_lis=set()
    for xx in x_lis:#xの約数
        q_lis|={xx}
    for q in list(q_lis):
        a=q
        b=0
        while a**5-b**5<=x:
            if a**5-b**5==x:
                print(a,b)
                sys.exit()
            a+=1
            b+=1
        a=q
        b=0
        while a**5-b**5<=x:
            if a**5-b**5==x:
                print(a,b)
                sys.exit()
            a+=1
            b-=1
        a=q
        b=0
        while a**5-b**5<=x:
            if a**5-b**5==x:
                print(a,b)
                sys.exit()
            a-=1
            b-=1
        


if __name__=='__main__':
    main()