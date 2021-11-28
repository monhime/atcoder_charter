import sys
def input(): return sys.stdin.readline().rstrip()

def main():
    a,k=map(int,input().split())
    sum_a=a
    day=0
    if k==0:
        print(2*10**12-a)
        sys.exit()
    while sum_a<2*10**12:
        sum_a+=1+k*sum_a
        day+=1
    print(day)

    

if __name__=='__main__':
    main()