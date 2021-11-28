a,b,c = sorted(list(map(int,input().split())))
if a == c:
    print("1")
elif a == b or b == c:
    print("2")
else:
    print("3")

