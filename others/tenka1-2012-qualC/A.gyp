import sys
def input(): return sys.stdin.readline().rstrip()
import math
def is_prime(n):
    if n==1:return False
    for k in range(2,int(math.sqrt(n))+1):
        if n%k==0:
            return False
    return True
def main():
    n=int(input())
    cunt=0
    for i in range(1,n):
        if is_prime(i):
            cunt+=1
    print(cunt)

if __name__=='__main__':
    main()