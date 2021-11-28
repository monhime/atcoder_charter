s=input()
count=0
ans=0
for i in range(len(s)):
    if s[i] in ['A','G','C','T']:
        count+=1
        ans=max(count,ans)
    else:
        count=0
print(ans)