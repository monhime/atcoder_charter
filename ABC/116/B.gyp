a_1=int(input())
a=[a_1]
for i in range(1000000):
    if a[-1]%2==0:
        a_next=a[-1]//2
    else:
        a_next=3*a[-1]+1
    if a_next in a:
        print(i+2)
        break

    a.append(a_next)