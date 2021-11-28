import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    mod = 10**9 + 7
    inf = 10**10
    
    n = int(input())
    s = list(input())
    q = int(input())
    TAB = [tuple(map(int,input().split())) for i in range(q)]
    swap_flag = False
    for t, a, b in TAB:
        _a = a - 1
        _b = b - 1
        if t == 2:
            swap_flag ^= True
            continue
        if swap_flag:
            _a = (_a + n) % (2*n)
            _b = (_b + n) % (2*n)
        s[_a], s[_b] = s[_b], s[_a]

    if swap_flag:
        print("".join(s[n:] + s[:n]))
    else:
        print("".join(s))
    
if __name__=='__main__':
    main()