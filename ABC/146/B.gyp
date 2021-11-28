n=int(input())
s=input()
new_s=""
for i in range(len(s)):
    new_s+=chr((ord(s[i])-ord('A')+n)%26+ord('A'))
print(new_s)
