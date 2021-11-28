n=int(input())
w=[input() for _ in range(n)]
if len(set(w))!=len(w):
    print("No")
else:
    for i in range(n-1):
        if w[i][-1]!=w[i+1][0]:
            print("No")
            break
    else:
        print("Yes")