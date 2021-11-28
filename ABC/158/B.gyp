n,a,b=map(int,input().split())
print(n//(a+b)*a+min(n%(a+b),a))