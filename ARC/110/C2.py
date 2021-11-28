import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n = int(input())
    P = list(map(int,input().split()))

    ans = []
    search = 0

    for i in range(n):
        if P[i] == search + 1 or i == n - 1:
            P[search: i + 1] = [search + 1] + P[search: i]
            ans += list(range(i, search, -1))
            search = i
        #print(P)
    for i in range(n):
        if P[i] != i + 1:
            print(-1)
            sys.exit()

    print('\n'.join(map(str,ans)))
    
        


if __name__=='__main__':
    main()