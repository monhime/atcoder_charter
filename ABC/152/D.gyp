import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    lis=[[0]*9 for _ in range(9)]
    for i in range(1,n+1):
        si=str(i)
        if int(si[-1])>0:
            lis[int(si[0])-1][int(si[-1])-1]+=1
    cunt=0
    for i in range(9):
        for j in range(9):
            cunt+=lis[i][j]*lis[j][i]
    print(cunt)
    
    

if __name__=='__main__':
    main()