import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,t=map(int,input().split())
    C=[]
    sum_a=0
    for i in range(n):
        a,b=map(int,input().split())
        C.append(a-b)
        sum_a+=a
    C.sort(reverse=True)
    if sum_a<=t:
            print(0)
            sys.exit()
    sum_c=0
    for i,c in enumerate(C):
        sum_c+=c
        if sum_a-sum_c<=t:
            print(i+1)
            break
    else:
        print(-1)





if __name__=='__main__':
    main()