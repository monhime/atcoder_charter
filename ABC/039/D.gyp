import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    h,w=map(int,input().split())
    SS=[input() for _ in range(h)]
    S=["#"*(w+2)]
    for i in range(h):
        S.append("#"+SS[i]+"#")
    S.append("#"*(w+2))
    A=[["."]*(w+2)for _ in range(h+2)]
    for i in range(1,h+1):
        for j in range(1,w+1):
            if S[i-1][j-1]=="#" and S[i-1][j]=="#" and S[i-1][j+1]=="#" and S[i][j-1]=="#" and S[i][j]=="#" and S[i][j+1]=="#" and S[i+1][j-1]=="#" and S[i+1][j]=="#" and S[i+1][j+1]=="#":
                A[i][j]="#"
    for i in range(1,h+1):
        for j in range(1,w+1):
            if S[i][j]=="#" and (A[i-1][j-1]=="." and A[i-1][j]=="." and A[i-1][j+1]=="." and A[i][j-1]=="." and A[i][j]=="." and A[i][j+1]=="." and A[i+1][j-1]=="." and A[i+1][j]=="." and A[i+1][j+1]=="."):
                print("impossible")
                sys.exit()
    print("possible") 
    for i in range(1,h+1):
        print(''.join(A[i][1:w+1]))


if __name__=='__main__':
    main()