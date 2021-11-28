import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    sum=0
    for i in range(1,n+1):
        if i%3!=0 and i%5!=0:sum+=i

    print(sum)
if __name__=='__main__':
    main()