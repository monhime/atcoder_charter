n=int(input())
A=[int(_) for _ in input().split()]
for i in range(n):
    if A[i]%2==0:
        if A[i]%3!=0 and A[i]%5!=0:
            print("DENIED")
            break
else:print("APPROVED")
