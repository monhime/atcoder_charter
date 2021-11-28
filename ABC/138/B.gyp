n=int(input())
A=[int(_) for _ in input().split()]
print('{:.16g}'.format(1/sum(1/x for x in A)))