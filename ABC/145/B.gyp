n=int(input())
s=input()
if n%2==0 and s[:n//2]==s[n//2:]:
    print("Yes")
else:print("No")