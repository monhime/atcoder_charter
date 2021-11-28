import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,l=map(int,input().split())
    S=[input() for _ in range(l)]
    Y=input()
    y=Y.index('o')
    if n==1:
        print(1)
        sys.exit()
    for i in range(l-1,-1,-1):
        if y==0:
            if S[i][y+1]=='-':
                y+=2
        elif y==2*n-2:
            if S[i][y-1]=='-':
                y-=2
        else:
            if S[i][y-1]=='-':
                y-=2
            elif S[i][y+1]=='-':
                y+=2
    print((y+2)//2)
                
if __name__=='__main__':
    main()