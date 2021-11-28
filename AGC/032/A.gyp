import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    B=list(map(int,input().split()))
    ans=[]
    for i in range(n):
        for j in range(len(B)-1,-1,-1):
            if B[j]==j+1:
                ans.append(B.pop(j))
                break
        else:
            print(-1)
            break
    else:
        print('\n'.join(map(str,ans[::-1])))

if __name__=='__main__':
    main()