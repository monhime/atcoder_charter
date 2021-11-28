import sys
def input(): return sys.stdin.readline().rstrip()
import math
def is_prime(n):
    if n==1:return False
    for k in range(2,int(math.sqrt(n))+1):
        if n%k==0:
            return False
    return True

def is_sosupoi(n):
    if n%2!=0 and n%10!=5 and sum(list(map(int, str(n))))%3!=0:
        return True
    else: 
        return False

def main():
    n=int(input())
    if (is_prime(n) or is_sosupoi(n)) and n!=1:
        print("Prime")
    else:
        print("Not Prime")

if __name__=='__main__':
    main()