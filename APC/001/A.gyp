import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    A=list(map(int,input().split()))
    B=list(map(int,input().split()))
    Da=[-(-(b-a)//2) for a,b in zip(A,B) if a<b]
    Db=[a-b for a,b in zip(A,B) if a>b ]
    if sum(B)-sum(A)>=max(sum(Da),sum(Db)):print("Yes")
    else:print("No")

if __name__=='__main__':
    main()
