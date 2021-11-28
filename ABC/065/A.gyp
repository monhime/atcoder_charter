x,a,b = map(int,input().split())
if x < b-a: print("dangerous")
elif b>a:print("safe")
else:print("delicious")