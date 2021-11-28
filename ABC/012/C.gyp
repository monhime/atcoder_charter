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
    divisors=make_divisors(2025-n)
    for i in range(len(divisors)):
        if divisors[i]<10 and divisors[-1-i]<10:
            print("{} x {}".format(divisors[i],divisors[-1-i]))

if __name__=='__main__':
    main()