from collections import Counter
_=input()
s=input()
s=Counter(s)
ans=1
for i in s.values():
    ans=(ans*(i+1))%(10**9+7)
print(ans-1)