import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    m,d=map(int,input().split())
    ans=0
    for i in range(1,m+1):
        for j in range(d+1):
            d_10=j//10
            d_1=j%10
            if d_10>=2 and d_1 >=2 and i == d_10*d_1:
                ans+=1
    print(ans)

if __name__=='__main__':
    main()