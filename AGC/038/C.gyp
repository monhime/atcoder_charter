import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    h,w,a,b=map(int,input().split())
    S=[[0]*w for _ in range(h)]
    for i in range(a):
        S[0][i]=1 
    cunt_col=[b-1]*a+[b]*(w-a)
    print(cunt_col)
    for i in range(1,h):
        cunt_row=a
        for j in range(w):
            if cunt_col[j]>0 and cunt_row>0:
                S[i][j]=1
                cunt_col[j]-=1
                cunt_row-=1
            if  cunt_row==0:
                break
        else:
            print("No")
            break
    else:
        if all(c==0 for c in cunt_col):
            for i in range(h):
                print(''.join(map(str,S[i])))
        else:
            print("No")

if __name__=='__main__':
    main()