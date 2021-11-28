import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    A=[int(_) for _ in input().split()]
    B=[int(_) for _ in input().split()]
    sumA,sumB=sum(A),sum(B)
    if sumA<sumB:
        print(-1)
        sys.exit()
    D=[0]*n
    sum_plus,sum_minus,ans=0,0,0
    for i in range(n):
        diff=A[i]-B[i]
        if diff>0:
            D.append(diff)
        elif diff<0:
            sum_minus-=diff
            ans+=1
    D.sort(reverse=True)
    if sum_minus==0:
        print(0)
        sys.exit()
    for d in D:
        ans+=1
        if sum_minus<=d:
            print(ans)
            break
        sum_minus-=d

if __name__=='__main__':
    main()