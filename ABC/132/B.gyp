n=int(input())
p=[int(_) for _ in input().split()]
count=0
for i in range(n-2):
    if p[i+1]!=min(p[i:i+3]) and p[i+1]!=max(p[i:i+3]):
        count+=1
print(count)
