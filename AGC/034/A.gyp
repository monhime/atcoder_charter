import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,a,b,c,d=map(int,input().split())
    s=input()
    for i in range(a,max(c,d)):
        if i+2<=n:
            if s[i:i+2]=='##':
                print("No")
                break
    else:
        if c<d:
            print("Yes")
        else:
            flag=False
            for i in range(b-1,d):    
                if s[i-1:i+2]=="...":
                    flag=True
            if flag==True:
                print("Yes")
            else:
                print("No")

if __name__=='__main__':
    main()