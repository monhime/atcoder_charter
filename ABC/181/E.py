import sys
def input(): return sys.stdin.readline().rstrip()
from bisect import bisect_left,bisect
def main():
    n, m = map(int,input().split())
    H = list(map(int,input().split()))
    W = list(map(int,input().split()))
    H.sort()
    H_cum = [0] * n #i番目までの偶ー奇ペアの差の和

    if n == 1:
        ans = 10 ** 9
        for w in W:
            ans = min(ans, abs(w - H[0]))
        print(ans)
        sys.exit()

    H_cum[0] = 0
    H_cum[1] = H[1] - H[0]
    for i in range(2, n):
        if i % 2 == 1:
            H_cum[i] = H_cum[i - 2] + H[i] - H[i - 1]
        else:
            H_cum[i] = H_cum[i - 1]
    
    H_cum_2 = [0] * n #i番目以降の奇-偶ペアの差の和
    H_cum_2[n - 1] = 0
    H_cum_2[n - 2] = H[n - 1] - H[n - 2]
    for i in range(n - 3, -1, -1):
        if i % 2 == 1:
            H_cum_2[i] = H_cum_2[i + 2] + H[i + 1] - H[i]
        else:
            H_cum_2[i] = H_cum_2[i + 1]

    ans = 10 ** 18
    for w in W:
        w_idx = bisect_left(H, w)
        if w_idx == n:
            cunt = H_cum[n - 1] + w - H[n - 1]
        elif w_idx == n - 1:
            cunt = H_cum[n - 1] + H[n - 1] - w 
        else:
            if w_idx % 2 == 0:
                cunt = H_cum[w_idx] + H_cum_2[w_idx + 1] + H[w_idx] - w
            else:
                cunt = H_cum[w_idx - 1] + H_cum_2[w_idx] + w - H[w_idx - 1]
        ans = min(ans, cunt)
    print(ans)

if __name__=='__main__':
    main()