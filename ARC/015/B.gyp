import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    day=[0]*6
    for i in range(n):
        t1,t2=map(float,input().split())
        if t1>=35:
            day[0]+=1
        elif t1>=30:
            day[1]+=1
        elif t1>=25:
            day[2]+=1
        if  t2>=25:
            day[3]+=1
        if t1<0:
            day[5]+=1
        elif t2<0:
            day[4]+=1
    print(" ".join(str(x) for x in day))

if __name__=='__main__':
    main()