import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n = int(input())
    AB = [[int(_) for _ in input().split()] for i in range(n)]
    dp = [0] * 400001
    A_lis = []
    for i in n:
        a = AB[i][0]
        b = AB[i][1]
        dp[a] += 1
        

if __name__=='__main__':
    main()