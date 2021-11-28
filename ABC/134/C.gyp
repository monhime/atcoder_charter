def main():
    import sys
    input = sys.stdin.readline #文字列をsplit()しない場合s=s[:-2]が必要

    n=int(input())
    A=[int(input())for _ in range(n)]
    a_max1=max(A)
    A1=A[:]
    A1.remove(a_max1)
    a_max2=max(A1)
    for i in range(n):
        if A[i]!=a_max1:print(a_max1)
        else:print(a_max2)

if __name__=='__main__':
    main()