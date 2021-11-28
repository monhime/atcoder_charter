n=int(input())
count=0 #個数
for i in range(1,n+1):
    #print("i："+str(i))
    #各iで約数15個ちょうど？
    count_yakusu=0 #約数の個数
    for j in range(1,i+1):
        #print("j："+str(j))
        if i%j==0:
            count_yakusu+=1
    if count_yakusu == 8 and i%2==1:
        count+=1
print(count)