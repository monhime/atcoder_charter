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
    n_list=make_divisors(n)
    len_list=len(n_list)
    if len_list%2==1:print(2*n_list[len_list//2]-2)
    else:
        print(n_list[len_list//2-1]+n_list[len_list//2]-2)

if __name__=='__main__':
    main()