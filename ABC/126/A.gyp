n,k=map(int,input().split())
s=input()
if k==1:
    s=s[0].lower()+s[1:]
else:
    s=s[:k-1]+s[k-1].lower()+s[k:]
print(s)