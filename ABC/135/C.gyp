from sys import stdin
def main():
    input=stdin.readline 
    #文字列をsplit()しない場合s=s[:-2]が必要

    n=int(input())
    A=[int(_) for _ in input().split()]
    sum_a=sum(A)
    B=[int(_) for _ in input().split()]
    for i in range(n):
        s=max(B[i]-A[i],0)
        A[i]-=min(A[i],B[i])
        A[i+1]-=min(A[i+1],s)
    print(sum_a-sum(A))

if __name__=='__main__':
    main()