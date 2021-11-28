import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n = int(input())
    L = sorted(list(map(int,input().split())))
    ans = 0
    for i in range(n-2):
        for j in range(i,n-1):
            if L[i] == L[j]: 
                continue
            for k in range(j,n):
                if L[j] == L[k]:
                    continue
                if L[i]+L[j] <= L[k]:
                    break
                ans+=1
    print(ans)

if __name__=='__main__':
    main()