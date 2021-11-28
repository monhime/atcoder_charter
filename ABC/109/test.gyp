n=int(input())
a=list(map(int, input().split()))

count=0
right=0
m=dict()
for left in range(n):

    while right<n and m.get(a[right],0)==0:
        #見たことある値を発見するまで右をすすめる
        m[a[right]]=m.get(a[right],0)+1
        right+=1
    count=max(count,right-left)
    m[a[left]]=m.get(a[left],1)-1
print(count)