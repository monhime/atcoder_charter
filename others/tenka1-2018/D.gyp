import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    s=2
    k=1
    for i in range(1,1000):
        if k==n:
            print("Yes")
            break
        if k>n:
            print("No")
            sys.exit()
        k+=s
        s+=1
    lis=[[]for _ in range(s)]
    x=1
    for i in range(s-1):
        for j in range(i+1,s):
            lis[i].append(x)
            lis[j].append(x)
            x+=1
    print(len(lis))
    for l in lis:
        print(str(len(l))+' '+' '.join(map(str,l)))

    

if __name__=='__main__':
    main()