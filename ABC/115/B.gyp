n=int(input())
p=[int(input())for i in range(n)]
p.sort(reverse=True)
p[0]//=2
print(sum(p))