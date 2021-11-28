import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,k=map(int,input().split())
    A=list(map(int,input().split()))
    dp=[False]*(k+1) #0:i個だったら必ず負ける，正:勝つ
    for i in range(min(A),k+1):
        for a in A:
            if i-a>=0 and not dp[i-a]:
                dp[i]=True
                break
        else:
            dp[i]=False
    if dp[k]:
        print("First")
    else:
        print("Second")

if __name__=='__main__':
    main()