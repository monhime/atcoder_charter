n=int(input())
s,t=input().split()
new_s=""
for s,t in zip(s,t):
    new_s+=s+t
print(new_s)