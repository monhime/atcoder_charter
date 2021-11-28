import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n = int(input())
    A = list(map(int,input().split())) #深さiの葉の数
    B = [0] * (n + 1)   #深さiの、葉でない頂点の数
    sum_A = sum(A[1:]) # その深さ以上の葉の数の和

    B[0] = 1 - A[0]
    if sum_A == 0:
        if B[0] == 0:
            print(1)
        else:
            print(-1)
        sys.exit()
    ans = 1
    for i in range(1, n + 1):
        sum_A -= A[i]
        max_b = min(2*B[i-1] - A[i], sum_A)
        if max_b + A[i] < B[i-1] or max_b < 0:
            print(-1)
            sys.exit()
        else:
            B[i] = max_b
        ans += A[i] + max_b

    print(ans)

if __name__=='__main__':
    main()