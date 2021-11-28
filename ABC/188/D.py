import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n, cc = map(int,input().split())
    D = []
    for i in range(n):
        a, b, c = map(int,input().split())
        a -= 1
        b -= 1
        D.append([a, c])
        D.append([b + 1, -c])
    D.sort()
    E = []
    E.append(D[0])
    for d in D[1:]:
        if E[-1][0] == d[0]:
            E[-1][1] += d[1]
        else:
            E.append(d)
    pre_day, cur_c = E[0]
    ans = 0
    for e in E[1:]:
        cur_day, cur_c_diff = e
        if cur_day > pre_day:
            ans += min(cc , cur_c) * (cur_day - pre_day)
        cur_c += cur_c_diff
        
        pre_day = cur_day
        
    print(ans)

if __name__=='__main__':
    main()