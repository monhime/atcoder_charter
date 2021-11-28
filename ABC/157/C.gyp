import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,m=map(int,input().split())
    num=[tuple(map(int,input().split())) for i in range(m)]
    num.sort()
    min_num=[0,0,0]
    flag=[True,True,True]
    for i in range(m):
        if flag[num[i][0]-1]:
            min_num[num[i][0]-1]=num[i][1]
            flag[num[i][0]-1]=False
        else:
            if min_num[num[i][0]-1]!=num[i][1]:
                print(-1)
                break
    else:
        if n==3:
            if min_num[0]==0:
                if flag[0]==True:
                    print(100+10*min_num[1]+min_num[2])
                else:print(-1)
            else:
                print(100*min_num[0]+10*min_num[1]+min_num[2])

        elif n==2:
            if min_num[0]==0:
                if flag[0]==True:
                    print(10+min_num[1])
                else:print(-1)
            else:
                print(10*min_num[0]+min_num[1]) 
        else:print(min_num[0])
if __name__=='__main__':
    main()