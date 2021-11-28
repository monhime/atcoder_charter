s=int(input())
n1=s//100
n2=s%100
if n1>12 or n1==0:
    if n2>12 or n2==0:print("NA")
    else:print("YYMM")
else:
    if n2>12 or n2==0:print("MMYY")
    else:print("AMBIGUOUS")
