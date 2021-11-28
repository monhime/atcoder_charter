import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    h,w=map(int,input().split())
    A=[[int(_) for _ in input().split()] for i in range(h)]
    ans=[]
    for i in range(h):
        if i%2==0:
            for j in range(w):
                if A[i][j]%2==1:
                    if j<w-1:
                        A[i][j+1]+=1
                        A[i][j]-=1
                        ans.append((i+1,j+1,i+1,j+2))
                    else:
                        if i+1==h:break
                        A[i+1][j]+=1
                        A[i][j]-=1
                        ans.append((i+1,j+1,i+2,j+1))
        else:
            for j in range(w-1,-1,-1):
                if A[i][j]%2==1:
                    if j>0:
                        A[i][j-1]+=1
                        A[i][j]-=1
                        ans.append((i+1,j+1,i+1,j))
                    else:
                        if i+1==h:break
                        A[i+1][j]+=1
                        A[i][j]-=1
                        ans.append((i+1,j+1,i+2,j+1))
    print(len(ans))
    for a in ans:
        print(*a)

if __name__=='__main__':
    main()