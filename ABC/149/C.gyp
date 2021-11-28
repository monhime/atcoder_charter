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
    x=int(input())
    while True:
        if is_prime(x)==True:
            print(x)
            break
        x+=1
if __name__=='__main__':
    main()