s=input()
dif=[]
for i in range(len(s)-2):
    dif.append(abs(753-int(s[i:i+3])))
print(min(dif))