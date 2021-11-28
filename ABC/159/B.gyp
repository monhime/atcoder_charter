s=input()
n=len(s)
for i in range((n+3)//4):
    if s[i]!=s[(n-3)//2-i] or  s[i]!=s[(n+1)//2+i] or s[i]!=s[-1-i]:
        print("No")
        break
else:print("Yes")