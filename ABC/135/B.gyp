n=int(input())
p=[int(_) for _ in input().split()]
p_sort=sorted(p)
count=0
for i in range(n):
    if p[i]!=p_sort[i]:
        count+=1
if count==0 or count==2:print("YES")
else:print("NO")