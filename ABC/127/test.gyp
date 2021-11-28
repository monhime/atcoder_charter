from math import ceil,floor
import time

start1 = time.time()
for i in range(10**7):
    ans=-(-i)//7
elapsed_time1 = time.time() - start1
print ("elapsed_time1:{0}".format(elapsed_time1) + "[sec]")

start2 = time.time()
for i in range(10**7):
    ans=ceil(i/7)
elapsed_time2 = time.time() - start2
print ("elapsed_time2:{0}".format(elapsed_time2) + "[sec]")

start3 = time.time()
for i in range(10**7):
    ans=floor(i/7)
elapsed_time3 = time.time() - start3
print ("elapsed_time3:{0}".format(elapsed_time3) + "[sec]")

start4 = time.time()
for i in range(10**7):
    ans=i//7
elapsed_time4 = time.time() - start4
print ("elapsed_time4:{0}".format(elapsed_time4) + "[sec]")
