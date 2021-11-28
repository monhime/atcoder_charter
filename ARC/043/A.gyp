import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,a,b=map(int,input().split())
    S=[int(input())for _ in range(n)]
    difS=max(S)-min(S)
    if difS==0:
        print(-1)
    else:
        p=b/difS
        q=a-p*sum(S)/n
        print(p,q)

if __name__=='__main__':
    main()