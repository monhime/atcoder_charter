import sys
def input(): return sys.stdin.readline().rstrip()
def prime_fact(n):
    prime_count = {}
    p_n= prime_fact_table[n]
    while p_n != 0:
        prime_count[p_n]=prime_count.get(p_n,0)+1
        n/=p_n
    prime_count[n]=prime_count.get(n,0)+1
    return prime_count

def main():
    n=int(input())
    A=list(map(int,input().split()))
    mod=10**9+7
    p_lis={}
    p_a_lis=[]

    global prime_fact_table
    prime_fact_table = [0] * (max(A) + 1)
    for i in xrange(2, n + 1):
        if prime_fact_table[i] == 0:
            for j in xrange(i + i, n + 1, i):
                prime_fact_table[j] = i

    for a in A:
        p_a_lis.append(prime_fact(a))
        for key in p_a_lis[-1]:
            if not p_lis.get(key,False) or p_lis[key]<p_a_lis[-1][key]:
                p_lis[key]=p_a_lis[-1][key]
    print(p_lis)
    print(p_a_lis)

    ans=0
    for i,a in enumerate(A):
        b=1
        for key in p_lis:
            b=(b*key**(p_lis[key]-p_a_lis[i].get(key,0)))%mod
        ans=(ans+b)%mod
    print(ans)

if __name__=='__main__':
    main()