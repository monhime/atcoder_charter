import sys
def input(): return sys.stdin.readline().rstrip()
from bisect import bisect_left,bisect
def main():
    h, w, m = map(int,input().split()) 
    h_lis = [0] * (h+1)
    w_lis = [0] * (w+1)
    bombs = set([tuple(map(int,input().split())) for i in range(m)])
    for hh, ww in bombs:
        h_lis[hh] += 1
        w_lis[ww] += 1
    max_h = max(h_lis)
    max_w = max(w_lis)
    h_max_index = [i for i, h in enumerate(h_lis) if h == max_h]
    w_max_index = [i for i, w in enumerate(w_lis) if w == max_w]
    for h_i in h_max_index:
        for w_i in w_max_index:
            if not (h_i, w_i) in bombs:
                print(h_lis[h_i] + w_lis[w_i])
                sys.exit()
    else:
        print(h_lis[h_i] + w_lis[w_i] - 1)

if __name__=='__main__':
    main()