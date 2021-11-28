import sys
def input(): return sys.stdin.readline().rstrip()
def prime_fact_factorial(n):
    global e
    e=[0]*(n+1)
    for i in range(2,n+1):
        cur=i
        for j in range(2,i+1):
            while cur%j==0:
                e[j]+=1
                cur//=j
def num(m):
    return len([x for x in e if x>=m-1])
def main():
    n=int(input())
    prime_fact_factorial(n)
    print(num(75)+num(25)*(num(3)-1)+num(15)*(num(5)-1)
        +num(5)*(num(5)-1)*(num(3)-2)//2)

if __name__=='__main__':
    main()