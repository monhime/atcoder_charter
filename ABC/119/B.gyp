n=int(input())
S=[[s for s in input().split()] for i in range(n)]
X=[float(s[0]) for s in S]
count =0
for i in range(n):
    if S[i][1]=="JPY":
        count+=float(S[i][0])
    else:
        count+=float(S[i][0])*380000.0
print(count)
