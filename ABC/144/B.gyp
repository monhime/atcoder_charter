n=int(input())
x_set=set()
for i in range(1,10):
    for j in range(1,10):
        x_set.update({i*j})
if n in x_set:
    print("Yes")
else:
    print("No")