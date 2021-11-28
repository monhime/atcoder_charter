import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    lis=[]
    for i in range(n):
        a,b=map(int,input().split())
        lis.append((b,a))
    lis.sort()
    time=0
    for l in lis:
        time+=l[1]
        if time>l[0]:
            print("No")
            break
    else:
        print("Yes")

if __name__=='__main__':
    main()